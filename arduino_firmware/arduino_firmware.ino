//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "pins.h"
#include "CANBus.h"
#include <TMC2130Stepper.h>
#include <Wire.h>

//----------------------------
// Mutually exclusive features - With STM32F103FC8T6 you can have USB serial or CANBus but not both.
// If you try to use both very likely neither will work.

// define this to use USB serial.
#define BUILD_SERIAL
// define this to use CANBus.
//#define BUILD_CANBUS

#if defined(BUILD_SERIAL) && defined(BUILD_CANBUS)
#error BUILD_SERIAL or BUILD_CANBUS.  Not both at once!
#endif

#ifdef BUILD_SERIAL
#define DEBUG(x)    Serial.print(x)
#define DEBUGLN(x)  Serial.println(x)
#else
#define DEBUG(x)    nop()
#define DEBUGLN(x)  nop()
#endif

//----------------------------
// sensor readings

// define this value to report sensor readings over serial (if BUILD_SERIAL is enabled)
#define DEBUG_SENSOR

#define SENSOR_BITS 12  // 10 is the default in arduino.  12 will get 4096 positions.
#if SENSOR_BITS == 12
  #define SENSOR_FULL_VALUE (4096.0)
#else
  #define SENSOR_FULL_VALUE (2048.0)
#endif
#define SENSOR_MIDDLE_VALUE (SENSOR_FULL_VALUE*0.5)
#define SENSOR_RANGE_HALF (SENSOR_FULL_VALUE*0.5)

// the angle last read by the sensor
double sensorAngle = 0;

//----------------------------
// define this value to report stepper calculations over serial (if BUILD_SERIAL is enabled)
//#define DEBUG_STEPPING

// motor gearbox parameters
#define STEPS_PER_DEGREE (105.0)
#define STEPS_PER_ROTATION (STEPS_PER_DEGREE*360)

// for TMC2130 StallGuard
#define STALL_VALUE 0 // [-64..63]

// the stepper driver interface
TMC2130Stepper driver = TMC2130Stepper(PIN_TMC_EN, PIN_TMC_DIR, PIN_TMC_STEP, PIN_SPI_TMC_CS, PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_CLK);
// the current motor position, in steps.
int steps = 0;


void setup() {
  #ifdef BUILD_SERIAL
  // serial must be first for enumeration.
    SERIALsetup();
  #endif

  SPIsetup();

  #ifdef BUILD_CANBUS
    CANsetup();
  #endif

  LEDsetup();

  SENSORsetup();

  // must come after SPIsetup
  MOTORsetup();
}


void SPIsetup() {
	SPI.begin();
	pinMode(PIN_SPI_MISO, INPUT_PULLUP);
}

#ifdef BUILD_CANBUS
void CANsetup() {
  DEBUGLN(F("CANsetup()"));
  //bool ret = CANInit(CAN_500KBPS, 2);  // CAN_RX mapped to PB8, CAN_TX mapped to PB9
  bool ret = CANInit(CAN_1000KBPS, 2);  // CAN_RX mapped to PB8, CAN_TX mapped to PB9
  if(ret) {
    DEBUGLN(F("CANsetup OK"));
  } else {
    DEBUGLN(F("CANsetup FAILED"));
  }
}
#endif

// prepare the TMC2130 driver
// See also https://revspace.nl/TMC2130
void MOTORsetup() {
  DEBUGLN(F("MOTORsetup()"));


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

#ifdef BUILD_SERIAL
void SERIALsetup() {
  // must be first, prevents connected USB devices from enumerating this device before it is ready.
  pinMode(PIN_BOOT1,OUTPUT);
  digitalWrite(PIN_BOOT1,LOW);
  // now get ready
  Serial.begin(115200);
  while(!Serial.availableForWrite());
  // now tell whoever we connect to that we're ready to be enumerated.
  digitalWrite(PIN_BOOT1,HIGH);

  DEBUGLN("Hello, world.");
}
#endif

void LEDsetup() {
  DEBUGLN("LEDsetup()");
  pinMode(PIN_PWM_RGB_B,OUTPUT);
  pinMode(PIN_PWM_RGB_R,OUTPUT);
  pinMode(PIN_PWM_RGB_G,OUTPUT);
}

void loop() {
  //testLED();

  SENSORdebug();
  testIPS2200();

  MOTORstep();
}

void MOTORstep() {
  double angleNow = steps / STEPS_PER_DEGREE;
  // get the difference between sensor and assumed motor position
  double diff = sensorAngle - angleNow;
  if(abs(diff)<1.0) return;

  // set the direction
  double dir = diff>0 ? 1 : -1;
  driver.shaft_dir(diff>0?1:0);
  
  #ifdef DEBUG_STEPPING
    DEBUG(sensorAngle);
    DEBUG("\t");
    DEBUG(angleNow);
    DEBUG("\t");
    DEBUG(diff);
    DEBUG("\t");
    DEBUGLN(dir);
  #endif

  // move the motor
  digitalWrite(PIN_TMC_STEP,HIGH);
  delayMicroseconds(1000);
  digitalWrite(PIN_TMC_STEP,LOW);
  delayMicroseconds(1000);

  // keep count
  steps+=dir;
  if(steps<0) steps += STEPS_PER_ROTATION;
  if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
}

void SENSORdebug() {
  #ifdef DEBUG_SENSOR
    double c  = ((double)analogRead(PIN_IPS_COS ) - SENSOR_MIDDLE_VALUE);
    double s  = ((double)analogRead(PIN_IPS_SIN ) - SENSOR_MIDDLE_VALUE);
    double cn = ((double)analogRead(PIN_IPS_COSN) - SENSOR_MIDDLE_VALUE);
    double sn = ((double)analogRead(PIN_IPS_SINN) - SENSOR_MIDDLE_VALUE);
    int a = c-cn;
    int b = s-sn;
    DEBUG(c);
    DEBUG(F("\t"));
    DEBUG(s);
    DEBUG(F("\t"));
    DEBUG(cn);
    DEBUG(F("\t"));
    DEBUG(sn);
    DEBUG(F("\t"));
    DEBUG(a);
    DEBUG(F("\t"));
    DEBUGLN(b);
  #endif
}

void SENSORsetup() {
  DEBUGLN(F("SENSORsetup()"));

  analogReadResolution(SENSOR_BITS);

  // use i2c to adjust the sensor receiver half-gain.  See IPS2200 programming guide section 3.5.3
  
  // read the current sensor value
  testIPS2200();
  steps = sensorAngle * STEPS_PER_DEGREE;
}

void testIPS2200() {
  // if sensor max VDD is 5 and min is 0 then middle is 2.5 and Renesas says the max/min of the sensor value will be +/-1.25 (1/4 VDD)
  // get and make -1...1
  double c  = ((double)analogRead(PIN_IPS_COS ) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  double s  = ((double)analogRead(PIN_IPS_SIN ) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  double cn = ((double)analogRead(PIN_IPS_COSN) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  double sn = ((double)analogRead(PIN_IPS_SINN) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  // one = half minus negative half
  double sx = c-cn; 
  double sy = s-sn;
  // limit check
  sx = min(1.0,max(sx,-1.0));
  sy = min(1.0,max(sy,-1.0));

  // get sensor angle as a value from 0...1
  double sensorAngleUnit = (atan2(sy,sx)+PI) / (2.0*PI);
  
  // debug
  //DEBUG(sx);
  //DEBUG("\t");
  //DEBUG(sy);
  //DEBUG("\t");
  //DEBUGLN(sensorAngle);

  // convert 0...1 -> 0...360
  // and store in global for later
  sensorAngle = 360.0 * sensorAngleUnit;

  // color wheel
  // convert 0...1 -> 0...255
  wheel((byte)(int)(255.0 * sensorAngleUnit));
}

void testLED() {
  for(int i=0;i<256;++i) {
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