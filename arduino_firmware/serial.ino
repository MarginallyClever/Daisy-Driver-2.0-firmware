#include "serial.h"

#ifdef BUILD_SERIAL
void SERIALsetup() {
  Serial.begin(SERIAL_BAUD);

  while(!Serial.availableForWrite());
  
  delay(2000);
  DEBUGLN("Hello, world.");
}
#endif