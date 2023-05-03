#pragma once
//-----------------------------------------------------------------------------

#define SERIAL_BAUD 115200

#ifdef BUILD_SERIAL
extern void SERIALsetup();
#endif