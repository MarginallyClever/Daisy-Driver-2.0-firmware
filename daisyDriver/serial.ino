#include "config.h"
//-----------------------------------------------------------------------------

char serialBufferIn[SERIAL_MAX_LEN];
int  serialReceived;

//-----------------------------------------------------------------------------

#ifdef BUILD_SERIAL

void SERIALsetup() {
  // must be first, prevents connected USB devices from enumerating this device before it is ready.
  //pinMode(PIN_BOOT1,OUTPUT);
  //digitalWrite(PIN_BOOT1,LOW);

  // now get ready
  Serial.begin(SERIAL_BAUD);

  while(!Serial.availableForWrite());
  // now tell whoever we connect to that we're ready to be enumerated.
  //digitalWrite(PIN_BOOT1,HIGH);

  delay(2000);

  serialReceived=0;

  DEBUGLN("Hello, world.");
}

void SERIALupdate() {
  if(Serial.available()) {
    char c = Serial.read();
    if(serialReceived < SERIAL_MAX_LEN-1) {
      serialBufferIn[serialReceived++]=c;
    }
    // new line, instruction done.
    if(c=='\n') {
      serialBufferIn[serialReceived]=0;
      SERIALparse();
      serialReceived=0;
    }
  }
}

int seen(char c) {
  for(int i=0;i<serialReceived;++i) {
    if(serialBufferIn[i]==c) {
      return i+1;
    }
  }
  return -1;
}

void SERIALparse() {
  int codePos = seen('G');
  if(codePos>=0) {
    int gcode = atoi(serialBufferIn+codePos);
    switch(gcode) {
      case 0:
      case 1:
        server.rapidMove();
        break;
      default:
        break;
    }
    return;
  }
  
  codePos = seen('M');
  if(codePos>=0) {
    int mcode = atoi(serialBufferIn+codePos);
    switch(mcode) {
      case 17:  SERIALenableMotors(true);  break;
      case 18:  SERIALenableMotors(false);  break;
      case 114:  server.reportAllMotorPositions();  break;
      default:
        break;
    }
    return;
  }
}


/**
  * look in the serial buffer for axis codes and enable/disable each.
  * if none are found, enable/disable all.
  * @params newState true to enable, false to disable.
  */
void SERIALenableMotors(bool newState) {
  bool seenAny=false;
  for(int i=0;i<NUM_AXIES;++i) {
    if(seen(axies[i])) {
      seenAny=true;
      server.enableOneMotor(i,newState);
    }
  }

  if(!seenAny) server.enableAllMotors(newState);
}
#endif