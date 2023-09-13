#pragma once
//-----------------------------------------------------------------------------

class LED {
  uint8_t r,g,b;

public:
  void setup();
  void wheel(byte WheelPos);
  void setColor(uint8_t r,uint8_t g,uint8_t b);
  void setRed(uint8_t r);
  void setBlue(uint8_t b);
  void setGreen(uint8_t g);

  void blink5();
  void showWheel();
};

//-----------------------------------------------------------------------------

extern LED light;