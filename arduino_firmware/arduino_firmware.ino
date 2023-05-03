//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//
// be sure to install "STM32 Boards" from Boards Manager.
// set tools > board to "Generic stm32f4 series"
// set tools > board part number to "Black F407VE"
// set tools > usb support to "CDC (generic 'Serial' supercedes U(S)ART)"
//-----------------------------------------------------------------------------
#include "config.h"


void setup() {
  #ifdef BUILD_SERIAL
    // serial must be first for enumeration.
    SERIALsetup();
  #endif
  printCANPins();
  MEMORYsetup();
  #ifdef BUILD_CANBUS
    CANsetup();
  #endif
  LEDsetup();
  SENSORsetup();
  MOTORsetup();
}


void readCANAddress() {
  pinMode(PIN_CAN_ADDR0,INPUT);
  pinMode(PIN_CAN_ADDR1,INPUT);
  pinMode(PIN_CAN_ADDR2,INPUT);
  pinMode(PIN_CAN_ADDR3,INPUT);
  pinMode(PIN_CAN_ADDR4,INPUT);
  pinMode(PIN_CAN_ADDR5,INPUT);

  CANBusAddress = ((uint8_t)digitalRead(PIN_CAN_ADDR0) << 0)
                | ((uint8_t)digitalRead(PIN_CAN_ADDR1) << 1)
                | ((uint8_t)digitalRead(PIN_CAN_ADDR2) << 2)
                | ((uint8_t)digitalRead(PIN_CAN_ADDR3) << 3)
                | ((uint8_t)digitalRead(PIN_CAN_ADDR4) << 4)
                | ((uint8_t)digitalRead(PIN_CAN_ADDR5) << 5);
}

void printCANPins() {
  readCANAddress();
  DEBUG("CAN address=");
  DEBUGLN(CANBusAddress);
}


void loop() {
  #ifdef BUILD_CANBUS
    CANstep();
  #endif
  SENSORread();
  MOTORstep();
}