//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "pins.h"
#include "CANBus.h"
#include <TMC2130Stepper.h>
#include <TMC2130Stepper_REGDEFS.h>
#include <TMC2130Stepper_UTILITY.h>


#define STEPS_PER_DEGREE (105.0)
#define STEPS_PER_ROTATION (STEPS_PER_DEGREE*360)

TMC2130Stepper driver = TMC2130Stepper(PIN_TMC_EN, PIN_TMC_DIR, PIN_TMC_STEP, PIN_SPI_TMC_CS, PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_CLK);

int steps = 0;

double sensorAngle = 0;

void setup() {
  // serial must be first for enumeration.
  SERIALsetup();
  LEDsetup();
  MOTORsetup();
  //CANsetup();
}

// prepare the TMC2130 driver
// See also https://revspace.nl/TMC2130
void MOTORsetup() {
  Serial.println("MOTORsetup()");
  driver.begin();
  driver.rms_current(600);  // Set stepper current to 600mA. The command is the same as command TMC2130.setCurrent(600, 0.11, 0.5);
  driver.stealthChop(1);  // Enable extremely quiet stepping
  driver.microsteps(0);

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

  //testIPS22200B();
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
  Serial.print(sensorAngle);
  Serial.print("\t");
  Serial.print(angleNow);
  Serial.print("\t");
  Serial.print(diff);
  Serial.print("\t");
  Serial.println(dir);

  // move the motor
  digitalWrite(PIN_TMC_STEP,HIGH);
  delay(5);
  digitalWrite(PIN_TMC_STEP,LOW);

  // keep count
  steps+=dir;
  if(steps<0) steps += STEPS_PER_ROTATION;
  if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
}


void testIPS22200B() {
  double r = ((double)analogRead(PIN_IPS_COS) - 350.0) / (650.0 - 350.0);
  double g = ((double)analogRead(PIN_IPS_SIN) - 350.0) / (650.0 - 350.0);
  r = min(1.0,max(r,0.0));
  g = min(1.0,max(g,0.0));
  analogWrite(PIN_PWM_RGB_B,r*255.0);
  analogWrite(PIN_PWM_RGB_R,g*255.0);
  analogWrite(PIN_PWM_RGB_G,0);

  Serial.print(analogRead(PIN_IPS_COS));
  Serial.print(F("\t"));
  Serial.print(analogRead(PIN_IPS_SIN));
  Serial.print(F("\t"));
  Serial.print(analogRead(PIN_IPS_COSN));
  Serial.print(F("\t"));
  Serial.println(analogRead(PIN_IPS_SINN));
}

void testIPS2200() {
  // get and make 0...1
  double sx = ((double)analogRead(PIN_IPS_COS) - 350.0) / (650.0 - 350.0);
  double sy = ((double)analogRead(PIN_IPS_SIN) - 350.0) / (650.0 - 350.0);

  double sxn = ((double)analogRead(PIN_IPS_COSN) - 350.0) / (650.0 - 350.0);
  double syn = ((double)analogRead(PIN_IPS_SINN) - 350.0) / (650.0 - 350.0);

  // convert 0...1 -> -1...1
  sx = (sx * 2.0) - 1.0; 
  sy = (sy * 2.0) - 1.0;
  // limit check
  sx = min(1.0,max(sx,-1.0));
  sy = min(1.0,max(sy,-1.0));
  // debug
  //Serial.print(sx);
  //Serial.print("\t");
  //Serial.println(sy);
  // store for later
  double sensorAngleRadians = atan2(sy,sx);
  sensorAngle = 180.0 + sensorAngleRadians * (180.0 / PI);
  // color wheel
  int angle = 255.0 * (sensorAngleRadians + PI) / (2.0*PI);
  wheel((byte)(int)angle);
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