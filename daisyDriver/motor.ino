#include "config.h"
//-----------------------------------------------------------------------------

#include <TMCStepper.h>
#include <TMCStepper_UTILITY.h>
#include <Wire.h>
#include <HardwareTimer.h>

//-----------------------------------------------------------------------------

#define R_SENSE 0.11f
#define RMS_CURRENT 570 // 0.4a s / 0.707 peak-to-peak current for TMC2130

#define STEP_TIMER_IRQ_PRIO 2

#define STEPPER_TIMER_RATE 2000000 // 2 Mhz
#define STEPPER_TIMER_TICKS_PER_US ((STEPPER_TIMER_RATE) / 1000000)
#define HAL_TIMER_TYPE_MAX 0xFFFF  // maximum value for 16 bit timer.

//-----------------------------------------------------------------------------

Motor motor;

HardwareTimer *timer = new HardwareTimer(TIM8);

// the stepper driver interface
#ifdef USE_SOFTWARE_SPI
TMC2130Stepper driver = TMC2130Stepper(PIN_SPI1_TMC_CS, R_SENSE, PIN_SPI1_MOSI, PIN_SPI1_MISO, PIN_SPI1_CLK); // Software SPI
#else
TMC2130Stepper driver = TMC2130Stepper(PIN_SPI1_TMC_CS, R_SENSE);  // hardware SPI
#endif


//-----------------------------------------------------------------------------

/**
 * prepare the TMC2130 driver
 * See also https://revspace.nl/TMC2130
 */
void Motor::setup() {
  DEBUGLN(F("setup()"));

  // set the current steps to the sensor reading
  steps = sensorAngleUnit * STEPS_PER_ROTATION;
  motor.setTargetPosition(sensorAngleUnit);

  // set pins
  pinMode(PIN_TMC_EN,OUTPUT);
  pinMode(PIN_TMC_DIR,OUTPUT);
  pinMode(PIN_TMC_STEP,OUTPUT);

  SPIsetup();

  driver.begin();
  driver.toff(5);           // enable StallGuard
  driver.rms_current(RMS_CURRENT);  // Set  RMS current
  driver.microsteps(0);    // Set microsteps (0,2,4,8,16)

  // Toggle stealthChop
  driver.en_pwm_mode(true);
  driver.pwm_autoscale(true);

  // enable the driver
  enable();

  uint32_t clockFrequency = timer->getTimerClkFreq();
  uint32_t prescale = clockFrequency/(STEPPER_TIMER_RATE);
  timer->setPrescaleFactor(min((uint32_t)HAL_TIMER_TYPE_MAX,prescale));
  timer->setOverflow(clockFrequency / prescale, TICK_FORMAT);
  timer->setPreloadEnable(false);

  interruptEnable();

  // Start the timer.
  timer->resume();
  timer->setInterruptPriority(STEP_TIMER_IRQ_PRIO, 0);
}

void Motor::interruptEnable() {
  // Attach an interrupt on overflow (update) of the timer.
  if(!timer->hasInterrupt()) timer->attachInterrupt(_stepInterrupt);
}

void Motor::interruptDisable() {
  timer->detachInterrupt();
}


void Motor::interruptOff() {
  __disable_irq();
}

void Motor::interruptOn() {
  __enable_irq();
}


void Motor::setCompare(const uint32_t overflow) {
  timer->setOverflow(overflow+1,TICK_FORMAT);
  if(overflow < timer->getCount()) {
    timer->refresh();
  }
}


inline uint32_t getCount() {
  return timer->getCount();
}


void SPIsetup() {
  SPI.setMOSI(PIN_SPI1_MOSI);
  SPI.setMISO(PIN_SPI1_MISO);
  SPI.setSCLK(PIN_SPI1_CLK);
	SPI.begin();
	pinMode(PIN_SPI1_MISO, INPUT_PULLUP);
}

/*
// slow way for debugging
void Motor::step() {
  double angleNow = steps / STEPS_PER_DEGREE;
  // get the difference between sensor and assumed  position
  double diff = targetPosition - angleNow;
  if(abs(diff)<1.0) return;

  // set the direction
  double dir = diff>0 ? 1 : -1;
  driver.shaft(diff>0);
  
  #ifdef DEBUG_STEPPING
    DEBUG(sensorAngle);
    DEBUG("\t");
    DEBUG(angleNow);
    DEBUG("\t");
    DEBUG(diff);
    DEBUG("\t");
    DEBUGLN(dir);
  #endif

  // move the 
  digitalWrite(PIN_TMC_STEP,HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(PIN_TMC_STEP,LOW);
  delayMicroseconds(stepDelay);

  // keep count
  steps+=dir;
  if(steps<0) steps += STEPS_PER_ROTATION;
  if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
}
*/

void _stepInterrupt() {
  motor.stepInterrupt();
}

void Motor::stepInterrupt() {
  static uint32_t nextMainISR = 0;

  interruptOff();
  setCompare(HAL_TIMER_TYPE_MAX);

  uint8_t maxLoops = 10;
  uint32_t minTicks;
  uint32_t nextTick=0;
  
  do {
    interruptOn();
    // STEP PHASE
    if(!nextMainISR && stepsDiffAbs>0) {
      // blink light
      state = (!state ? 255:0);

      // move the 
      digitalWrite(PIN_TMC_STEP,HIGH);
      digitalWrite(PIN_TMC_STEP,LOW);
      // keep count
      stepsDiffAbs--;
      steps += stepDir;
      if(steps<0) steps += STEPS_PER_ROTATION;
      if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
    }
    // BLOCK PHASE
    if(!nextMainISR) nextMainISR = stepDelay;

    // timing
    const uint32_t interval = min((uint32_t)HAL_TIMER_TYPE_MAX,nextMainISR);
    nextMainISR -= interval;
    nextTick += interval;

    interruptOff();
    minTicks = getCount() + (uint32_t)STEPPER_TIMER_TICKS_PER_US;
    if (!--maxLoops) nextTick = minTicks;
  } while(nextTick < minTicks);

  if(stepsDiffAbs==0) {
    interruptDisable();
  } else {
    setCompare(nextTick);
  }
  interruptOn();
}


/**
 * @param angleUnit 0...1
 */
void Motor::setTargetPosition(float angleUnit) {
  targetSteps = angleUnit * STEPS_PER_ROTATION;
  int32_t diff = targetSteps - steps;
  stepsDiffAbs = abs(diff);

  // set the direction
  stepDir = diff>0 ? 1 : -1;
  digitalWrite(PIN_TMC_DIR,(diff>0)?HIGH:LOW);

  interruptEnable();
}

float Motor::getTargetPosition() {
  return targetSteps / STEPS_PER_ROTATION;
}

void Motor::setTargetVelocity(float degPerS) {
  stepDelay = STEPPER_TIMER_RATE / (degPerS * STEPS_PER_DEGREE);
}

void Motor::enable() {
  digitalWrite(PIN_TMC_EN,LOW);
}

void Motor::disable() {
  digitalWrite(PIN_TMC_EN,HIGH);
}