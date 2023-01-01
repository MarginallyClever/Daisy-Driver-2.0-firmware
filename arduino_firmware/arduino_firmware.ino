//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "pins.h"
#include "CANBus.h"

void setup() {
  SERIALsetup();
  //CANsetup();
  LEDsetup();
}

void SERIALsetup() {
  pinMode(PIN_BOOT1,OUTPUT);
  digitalWrite(PIN_BOOT1,LOW);
  Serial.begin(115200);
  while(!Serial.available());
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
  testIPS22200B();
  //testIPS2200();
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

  delay(100);
}

void testIPS2200() {
  double sx = (double)analogRead(PIN_IPS_COS)/1024.0;
  double sy = (double)analogRead(PIN_IPS_SIN)/1024.0;
  Serial.print(sx);
  Serial.print("\t");
  Serial.println(sy);

  double angle = atan2(sx,sy);
  angle *= 255.0 / (2.0*PI);

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