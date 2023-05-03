#include "config.h"

#include <TMCStepper.h>
#include <TMCStepper_UTILITY.h>
#include <Wire.h>

#define R_SENSE 0.11f

// the stepper driver interface
#ifdef USE_SOFTWARE_SPI
TMC2130Stepper driver = TMC2130Stepper(PIN_SPI1_TMC_CS, R_SENSE, PIN_SPI1_MOSI, PIN_SPI1_MISO, PIN_SPI1_CLK); // Software SPI
#else
TMC2130Stepper driver = TMC2130Stepper(PIN_SPI1_TMC_CS, R_SENSE);  // hardware SPI
#endif


// the current motor position, in steps.
int steps = 0;
int stepDelay = 1000;

//----------------------------

// prepare the TMC2130 driver
// See also https://revspace.nl/TMC2130
void MOTORsetup() {
  DEBUGLN(F("MOTORsetup()"));

  pinMode(PIN_TMC_EN,OUTPUT);
  pinMode(PIN_TMC_DIR,OUTPUT);
  pinMode(PIN_TMC_STEP,OUTPUT);

  SPIsetup();

  driver.begin();
  driver.toff(5);           // enable StallGuard
  driver.rms_current(600);  // Set motor RMS current
  driver.microsteps(1);    // Set microsteps (1,2,4,8,16)

  // Toggle stealthChop
  driver.en_pwm_mode(true);
  driver.pwm_autoscale(true);

  // enable the driver
  digitalWrite(PIN_TMC_EN,LOW);
}


void SPIsetup() {
  SPI.setMOSI(PIN_SPI1_MOSI);
  SPI.setMISO(PIN_SPI1_MISO);
  SPI.setSCLK(PIN_SPI1_CLK);
	SPI.begin();
	//pinMode(PIN_SPI1_MISO, INPUT_PULLUP);
}


void MOTORstep() {
  double angleNow = steps / STEPS_PER_DEGREE;
  // get the difference between sensor and assumed motor position
  double diff = sensorAngle - angleNow;
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

  // move the motor
  digitalWrite(PIN_TMC_STEP,HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(PIN_TMC_STEP,LOW);
  delayMicroseconds(stepDelay);

  // keep count
  steps+=dir;
  if(steps<0) steps += STEPS_PER_ROTATION;
  if(steps>=STEPS_PER_ROTATION) steps -= STEPS_PER_ROTATION;
}