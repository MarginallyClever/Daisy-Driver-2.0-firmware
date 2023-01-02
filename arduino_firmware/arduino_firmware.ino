//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "pins.h"
#include "CANBus.h"
#include <TMC2130Stepper.h>

// define this value to report sensor readings
#define DEBUG_SENSOR

// motor gearbox parameters
#define STEPS_PER_DEGREE (105.0)
#define STEPS_PER_ROTATION (STEPS_PER_DEGREE*360)

// sensor readings
#define SENSOR_BITS 12  // 10 is the default in arduino.  12 will get 4096 positions.
#if SENSOR_BITS == 12
  #define SENSOR_HIGH_VALUE (2700.0)
  #define SENSOR_LOW_VALUE (1400.0)
#else
  #define SENSOR_HIGH_VALUE (675.0)
  #define SENSOR_LOW_VALUE (350.0)
#endif
#define SENSOR_RANGE (SENSOR_HIGH_VALUE - SENSOR_LOW_VALUE)

// for TMC2130 StallGuard
#define STALL_VALUE 0 // [-64..63]

// the stepper driver interface
TMC2130Stepper driver = TMC2130Stepper(PIN_TMC_EN, PIN_TMC_DIR, PIN_TMC_STEP, PIN_SPI_TMC_CS, PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_CLK);
// the number of steps taken by the motor
int steps = 0;
// the angle last read by the sensor
double sensorAngle = 0;


void setup() {
  // serial must be first for enumeration.
  SERIALsetup();
  LEDsetup();
  SENSORsetup();
  MOTORsetup();
  //CANsetup();
}


void CANsetup() {
  Serial.println(F("CANsetup()"));
  //bool ret = CANInit(CAN_500KBPS, 2);  // CAN_RX mapped to PB8, CAN_TX mapped to PB9
  bool ret = CANInit(CAN_1000KBPS, 2);  // CAN_RX mapped to PB8, CAN_TX mapped to PB9
  if(ret) {
    Serial.println(F("CANsetup OK"));
  } else {
    Serial.println(F("CANsetup FAILED"));
  }
}

// prepare the TMC2130 driver
// See also https://revspace.nl/TMC2130
void MOTORsetup() {
  Serial.println(F("MOTORsetup()"));

	SPI.begin();
	pinMode(PIN_SPI_MISO, INPUT_PULLUP);

  driver.begin();
  driver.rms_current(600);  // Set stepper current to 600mA. The command is the same as command TMC2130.setCurrent(600, 0.11, 0.5);
  driver.stealthChop(1);  // Enable extremely quiet stepping
  driver.microsteps(0);

  // StallGuard magic
  driver.toff(3);
  driver.tbl(1);
  driver.hysteresis_start(4);
  driver.hysteresis_end(-2);
  driver.diag1_stall(1);
  driver.diag1_active_high(1);
  driver.coolstep_min_speed(0xFFFFF); // 20bit max
  driver.THIGH(0);
  driver.semin(5);
  driver.semax(2);
  driver.sedn(0b01);
  driver.sg_stall_value(STALL_VALUE);

  // enable the driver
  digitalWrite(PIN_TMC_EN,LOW);
}

void SERIALsetup() {
  // must be first, prevents connected USB devices from enumerating this device before it is ready.
  pinMode(PIN_BOOT1,OUTPUT);
  digitalWrite(PIN_BOOT1,LOW);
  // now get ready
  Serial.begin(115200);
  while(!Serial.availableForWrite());
  // now tell whoever we connect to that we're ready to be enumerated.
  digitalWrite(PIN_BOOT1,HIGH);

  Serial.println("Hello, world.");
}

void LEDsetup() {
  Serial.println("LEDsetup()");
  pinMode(PIN_PWM_RGB_B,OUTPUT);
  pinMode(PIN_PWM_RGB_R,OUTPUT);
  pinMode(PIN_PWM_RGB_G,OUTPUT);
}

void loop() {
  //testLED();

  SENSORdebug();
  testIPS2200();

  testMotor1();
}

void testMotor1() {
  double angleNow = steps / STEPS_PER_DEGREE;
  // get the difference between sensor and assumed motor position
  double diff = sensorAngle - angleNow;
  if(abs(diff)<1.0) return;

  // set the direction
  double dir = diff>0 ? 1 : -1;
  driver.shaft_dir(diff>0?1:0);
  
  // debug
  //Serial.print(sensorAngle);
  //Serial.print("\t");
  //Serial.print(angleNow);
  //Serial.print("\t");
  //Serial.print(diff);
  //Serial.print("\t");
  //Serial.println(dir);

  // move the motor
  digitalWrite(PIN_TMC_STEP,HIGH);
  delayMicroseconds(2100);
  digitalWrite(PIN_TMC_STEP,LOW);
  delayMicroseconds(2100);

  // keep count
  steps+=dir;
  if(steps<0) steps += STEPS_PER_ROTATION;
  if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
}

void SENSORdebug() {
#ifdef DEBUG_SENSOR
  Serial.print(analogRead(PIN_IPS_COS));
  Serial.print(F("\t"));
  Serial.print(analogRead(PIN_IPS_SIN));
  Serial.print(F("\t"));
  Serial.print(analogRead(PIN_IPS_COSN));
  Serial.print(F("\t"));
  Serial.println(analogRead(PIN_IPS_SINN));
#endif
}

void SENSORsetup() {
  Serial.println(F("SENSORsetup()"));
  analogReadResolution(12);
  testIPS2200();
  steps = sensorAngle * STEPS_PER_DEGREE;
}

void testIPS2200() {
  // get and make 0...1
  double sx = ((double)analogRead(PIN_IPS_COS) - SENSOR_LOW_VALUE) / SENSOR_RANGE;
  double sy = ((double)analogRead(PIN_IPS_SIN) - SENSOR_LOW_VALUE) / SENSOR_RANGE;

  double sxn = ((double)analogRead(PIN_IPS_COSN) - SENSOR_LOW_VALUE) / SENSOR_RANGE;
  double syn = ((double)analogRead(PIN_IPS_SINN) - SENSOR_LOW_VALUE) / SENSOR_RANGE;

  // convert 0...1 -> -1...1
  sx = (sx * 2.0) - 1.0; 
  sy = (sy * 2.0) - 1.0;
  // limit check
  sx = min(1.0,max(sx,-1.0));
  sy = min(1.0,max(sy,-1.0));

  // get sensor angle as a value from 0...1
  double sensorAngleUnit = (atan2(sy,sx)+PI) / (2.0*PI);
  
  // debug
  //Serial.print(sx);
  //Serial.print("\t");
  //Serial.print(sy);
  //Serial.print("\t");
  //Serial.println(sensorAngle);

  // convert 0...1 -> 0...360
  // and store in global for later
  sensorAngle = 360.0 * sensorAngleUnit;

  // color wheel
  // convert 0...1 -> 0...255
  wheel((byte)(int)(255.0 * sensorAngleUnit));
}

void testLED() {
  for(float i=0;i<256;++i) {
    wheel(i);
    delay(5);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
void wheel(byte WheelPos) {
  if(WheelPos < 85) {
    analogWrite(PIN_PWM_RGB_B,WheelPos * 3);
    analogWrite(PIN_PWM_RGB_R,255 - WheelPos * 3);
    analogWrite(PIN_PWM_RGB_G,0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    analogWrite(PIN_PWM_RGB_B,255 - WheelPos * 3);
    analogWrite(PIN_PWM_RGB_R,0);
    analogWrite(PIN_PWM_RGB_G,WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    analogWrite(PIN_PWM_RGB_B,0);
    analogWrite(PIN_PWM_RGB_R,WheelPos * 3);
    analogWrite(PIN_PWM_RGB_G,255 - WheelPos * 3);
  }
}