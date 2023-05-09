#include "config.h"
//-----------------------------------------------------------------------------

#define COB_NMT_CONTROL 0x000
#define COB_SDO_SEND    0x580
#define COB_SDO_RECEIVE 0x600

#define MAKE_COB_ID(functionCode,address) (functionCode | address)
#define COB_GET_FUNCTION_CODE(cobID)      (cobID&0b11110000000)
#define COB_GET_ADDRESS(cobID)            (cobID&0b00001111111)

#define NUM_AXIES (6)

//-----------------------------------------------------------------------------

char axies[NUM_AXIES]  = {'X','Y','Z','U','V','W'};
float nextPos[NUM_AXIES];
float lastHeard[NUM_AXIES];
uint32_t lastReq=0;
//-----------------------------------------------------------------------------

void APPupdate() {
  APPreadCAN();

  if(CANbus.CANBusAddress==0) {
    uint32_t t = millis();
    if(t - lastReq > 100) {
      lastReq=t;
      APPrequestAllPositions();
    }
  }
}


void APPreadCAN() {
  CAN_msg_t inbound;
  CANbus.receive(&inbound);
  uint8_t functionCode = COB_GET_FUNCTION_CODE(inbound.id);
  if(functionCode == COB_SDO_SEND) {
    if(CANbus.CANBusAddress!=0) return;  // only root cares about receiving messages.

    int index = COB_GET_ADDRESS(inbound.id);  // from who?
    if(index<0 || index>=NUM_AXIES) return;

    int i=0;
    int id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) lastHeard[index] = CAN_GET_FLOAT(inbound,i) * 360.0;
    } else if( id == CAN_SET ) {
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_SET_POSITION) targetPosition = CAN_GET_FLOAT(inbound,i) * 360.0;
    }
  } else if( functionCode == COB_SDO_RECEIVE) {
    int index = COB_GET_ADDRESS(inbound.id);  // for who?
    if(index != CANbus.CANBusAddress) return;  // not for me

    int i=0;
    int id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) APPsendSensor();
    }
  }
}


void APPsendSensor() {
  CAN_msg_t CAN_TX_msg;
  CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_SEND,CANbus.CANBusAddress);
  CAN_START(CAN_TX_msg);
  CAN_ADD_LONG(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ);
  CAN_ADD_SHORT(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ_POSITION);
  CAN_ADD_FLOAT(CAN_TX_msg,sensorAngleUnit);
  CANbus.send(&CAN_TX_msg);
}


void APPrequestOnePosition(uint8_t index) {
  if(index==0 && CANbus.CANBusAddress==0) {
    lastHeard[index] = sensorAngleUnit * 360.0;
  } else {
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_RECEIVE,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ);
    CAN_ADD_SHORT(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ_POSITION);
    CANbus.send(&CAN_TX_msg);
  }
}

void APPrequestAllPositions() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    APPrequestOnePosition(i);
  }
}


void APPsendOnePosition(int index,float v) {
  if(index==0 && CANbus.CANBusAddress==0) {
    targetPosition = v;
  } else {
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_SEND,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_SET);  // 0x2013 custom parameter (read only)
    CAN_ADD_SHORT(CAN_TX_msg,CAN_SET_POSITION);
    CAN_ADD_FLOAT(CAN_TX_msg,v);
    CANbus.send(&CAN_TX_msg);
  }
}


void APPrapidMove() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    int pos = seen(axies[i]);
    if(pos>=0) {
      v = atof(serialBufferIn+pos)/360.0;
      nextPos[i] = v;
      APPsendOnePosition(i,v);
    }
  }
}


void APPreportAllMotorPositions() {
  Serial.print("M114");
  for(int i=0;i<NUM_AXIES;++i) {
    Serial.print(' ');
    Serial.print(axies[i]);
    Serial.print(lastHeard[i],2);
  }
  Serial.println();
}

