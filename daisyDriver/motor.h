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

extern uint8_t MOTORstate;

//----------------------------

extern void MOTORsetup();
extern void MOTORstep();
extern void MOTORsetCompare(uint32_t overflow);

extern void MOTORinterruptOff();
extern void MOTORinterruptOn();

extern void MOTORsetTargetPosition(float angleUnit);
extern void MOTORsetTargetVelocity(float degPerS);