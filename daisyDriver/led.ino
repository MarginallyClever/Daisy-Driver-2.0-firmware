#include "config.h"
//-----------------------------------------------------------------------------

LED light;

//-----------------------------------------------------------------------------

void LED::setup() {
  pinMode(PIN_PWM_RGB_B,OUTPUT);
  pinMode(PIN_PWM_RGB_R,OUTPUT);
  pinMode(PIN_PWM_RGB_G,OUTPUT);
  blink5();
}

void LED::blink5() {
  for(int i=0;i<5;++i) {
    setColor(255,255,255);
    delay(50);
    setColor(0,0,0);
    delay(50);
  }
}


void LED::showWheel() {
  for(int i=0;i<256;++i) {
    wheel(i);
    delay(5);
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
void LED::wheel(byte WheelPos) {
  if(WheelPos < 85) {
    setColor(255 - WheelPos * 3,0,WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    light.setColor(0,WheelPos * 3,255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    setColor(WheelPos * 3,255 - WheelPos * 3,0);
  }
}


void LED::setColor(uint8_t r,uint8_t g,uint8_t b) {
  analogWrite(PIN_PWM_RGB_R,r);
  analogWrite(PIN_PWM_RGB_G,g);
  analogWrite(PIN_PWM_RGB_B,b);
}