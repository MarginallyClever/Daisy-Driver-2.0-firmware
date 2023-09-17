#pragma once
//-----------------------------------------------------------------------------

//#define USE_SOFTWARE_SPI

// motor gearbox parameters
#define STEPS_PER_DEGREE (105.0)
#define STEPS_PER_ROTATION (STEPS_PER_DEGREE*360)

// for TMC2130 StallGuard
#define STALL_VALUE 0 // [-64..63]

//----------------------------

extern int32_t steps;

extern uint32_t stepDelay;

extern uint8_t state;

//----------------------------

class Motor {
public:
  // the current  position, in steps.
  int32_t steps = 0;
  int32_t targetSteps = 0;
  uint8_t stepDir = 0;
  uint32_t stepsDiffAbs = 0;
  uint32_t stepDelay = 1000000;

  // 0...360
  float targetPosition = 0;

  uint8_t state;

  void setup();
  void step();
  void setCompare(uint32_t overflow);

  void interruptOff();
  void interruptOn();

  void setTargetPosition(float angleUnit);
  void setTargetVelocity(float degPerS);

  float getTargetPosition();

  void enable();
  void disable();
  void stepInterrupt();

private:
  void interruptEnable();
  void interruptDisable();
};

extern Motor motor;

