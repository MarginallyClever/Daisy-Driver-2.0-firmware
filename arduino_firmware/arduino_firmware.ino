//-----------------------------------------------------------------------------
// Daisy Driver firmware
// 2022-12-21 dan@marginallyclever.com
//-----------------------------------------------------------------------------
#include "config.h"

//----------------------------

void setup() {
  #ifdef BUILD_SERIAL
  // serial must be first for enumeration.
    SERIALsetup();
  #endif

  MEMORYsetup();

  #ifdef BUILD_CANBUS
    CANsetup();
  #endif

  LEDsetup();

  SENSORsetup();

  // must come after SPIsetup
  MOTORsetup();
}


#ifdef BUILD_SERIAL
void SERIALsetup() {
  // must be first, prevents connected USB devices from enumerating this device before it is ready.
  pinMode(PIN_BOOT1,OUTPUT);
  digitalWrite(PIN_BOOT1,LOW);
  // now get ready
  Serial.begin(115200);
  while(!Serial.availableForWrite());
  // now tell whoever we connect to that we're ready to be enumerated.
  digitalWrite(PIN_BOOT1,HIGH);

  DEBUGLN("Hello, world.");
}
#endif


void LEDsetup() {
  DEBUGLN("LEDsetup()");
  pinMode(PIN_PWM_RGB_B,OUTPUT);
  pinMode(PIN_PWM_RGB_R,OUTPUT);
  pinMode(PIN_PWM_RGB_G,OUTPUT);
}


void loop() {
  #ifdef BUILD_CANBUS
    CANstep();
  #endif
  SENSORread();
  MOTORstep();
}