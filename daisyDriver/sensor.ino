#include "sensor.h"

// the angle last read by the sensor
float sensorAngleUnit = 0;


void SENSORsetup() {
  DEBUGLN(F("SENSORsetup()"));

  analogReadResolution(SENSOR_BITS);

  // use i2c to adjust the sensor receiver half-gain.  See IPS2200 programming guide section 3.5.3
  
  // read the current sensor value
  SENSORread();
  steps = sensorAngleUnit * STEPS_PER_ROTATION;
  targetPosition = sensorAngleUnit * 360.0;
}


void SENSORread() {
  // if sensor max VDD is 5 and min is 0 then middle is 2.5 and Renesas says the max/min of the sensor value will be +/-1.25 (1/4 VDD)
  // get and make -1...1
  float c  = ((float)analogRead(PIN_IPS_COS ) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  float s  = ((float)analogRead(PIN_IPS_SIN ) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  float cn = ((float)analogRead(PIN_IPS_COSN) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  float sn = ((float)analogRead(PIN_IPS_SINN) - SENSOR_MIDDLE_VALUE) / SENSOR_RANGE_HALF;
  // one = half minus negative half
  float sx = c-cn; 
  float sy = s-sn;
  // limit check
  //sx = minf(1.0,maxf(sx,-1.0));
  //sy = minf(1.0,maxf(sy,-1.0));

  // get sensor angle as a value from 0...1
  // and store in global for later
  sensorAngleUnit = (atan2(sy,sx)+PI) / (2.0*PI);
  
  #ifdef DEBUG_SENSOR
    // debug
    DEBUG(analogRead(PIN_IPS_COS ) );    DEBUG('\t');
    DEBUG(analogRead(PIN_IPS_SIN ) );    DEBUG('\t');
    DEBUG(c );    DEBUG('\t');
    DEBUG(s );    DEBUG('\t');
    DEBUG(cn);    DEBUG('\t');
    DEBUG(sn);    DEBUG('\t');
    DEBUG(sx);    DEBUG('\t');
    DEBUG(sy);    DEBUG('\t');
    DEBUGLN(sensorAngleUnit);
  
    // color wheel
    // convert 0...1 -> 0...255
    wheel((byte)(int)(255.0 * sensorAngleUnit));
  #endif
}