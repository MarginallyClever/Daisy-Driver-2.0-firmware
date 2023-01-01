//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "pins.h"

void setup() {
  SERIALsetup();
  LEDsetup();
}

void SERIALsetup() {
  pinMode(PIN_BOOT1,OUTPUT);
  digitalWrite(PIN_BOOT1,LOW);
  Serial.begin(250000);
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
  int r = (double)analogRead(PIN_IPS_COS) * 16.0 / 1024.0;
  int g = (double)analogRead(PIN_IPS_SIN) * 16.0 / 1024.0;
  analogWrite(PIN_PWM_RGB_B,r);
  analogWrite(PIN_PWM_RGB_R,g);
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