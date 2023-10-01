#pragma once
//-----------------------------------------------------------------------------

// define this to use USB serial.
#define BUILD_SERIAL
// define this to use CANBus.
#define BUILD_CANBUS

// define this value to report sensor readings over serial (if BUILD_SERIAL is enabled)
//#define DEBUG_SENSOR

// define this value to report stepper calculations over serial (if BUILD_SERIAL is enabled)
//#define DEBUG_STEPPING

// uncomment to turn on serial debugging
//#define DEBUG_CAN
// uncomment to report CAN send fails over serial.
//#define CAN_REPORT_FAIL


#ifdef BUILD_CANBUS
  //#define CAN_SPEED       CAN_50KBPS
  //#define CAN_SPEED       CAN_100KBPS
  #define CAN_SPEED       CAN_500KBPS
  //#define CAN_SPEED       CAN_1000KBPS

  // 2023-09-19 Causes board to halt the first time the interrupt is called.  STM is aware of the problem.
  //#define CAN_ENABLE_RX0_INTERRUPT  
  //#define CAN_ENABLE_RX1_INTERRUPT  
#endif


#define NUM_AXIES (6)

/**
 * Every client that replies to a ADDRESS_EVERYONE message delays their response by this * their CAN id.
 * this is a workaround to prevent overflow on the server until the CAN receive interrupt can be fixed.
 */
#define CAN_ADDRESS_EVERYONE_DELAY 10 //ms

/**
 * When server is polling continuously for positions... this is the delay between polling requests.
 */
#define POSITION_UPDATE_INTERVAL  100 // ms

// motor gearbox parameters
#define STEPS_PER_DEGREE (105.0)
#define STEPS_PER_ROTATION (STEPS_PER_DEGREE*360)


//-----------------------------------------------------------------------------

#ifdef BUILD_SERIAL
  #define DEBUG(x)        Serial.print(x)
  #define DEBUG2(x0,x1)   Serial.print(x0,x1)
  #define DEBUGLN(x)      Serial.println(x)
#else
  #define NOP __asm__("nop\n\t")
  #define DEBUG(x)        NOP
  #define DEBUG2(x0,x1)   NOP
  #define DEBUGLN(x)      NOP
#endif

#include "pins.h"
#include "serial.h"
#include "CANBus.h"
#include "CANParser.h"
#include "memory.h"
#include "sensor.h"
#include "motor.h"
#include "led.h"
#include "CANOpen.h"
#include "client.h"
#include "server.h"
