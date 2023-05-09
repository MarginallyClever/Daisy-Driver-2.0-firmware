#include "config.h"
//-----------------------------------------------------------------------------

#define ADDRESS_EVERYONE 0x7F  // 0b00001111111

#define COB_NMT_CONTROL 0x000
#define COB_SDO_SEND    0x580
#define COB_SDO_RECEIVE 0x600

#define MAKE_COB_ID(functionCode,address) (functionCode | address)
#define COB_GET_FUNCTION_CODE(cobID)      (cobID&0x780)  // 0b11110000000
#define COB_GET_ADDRESS(cobID)            (cobID&0x07F)  // 0b00001111111


#define NUM_AXIES (6)

//-----------------------------------------------------------------------------

char axies[NUM_AXIES]  = {'X','Y','Z','U','V','W'};
float nextPos[NUM_AXIES];
float lastHeard[NUM_AXIES];
uint32_t lastReq=0;
float velocityDegPerS = 10;
//-----------------------------------------------------------------------------

void APPsetup() {
  APPsetVelocity(velocityDegPerS);
}

void APPtoggleCANState() {
  CANstate = (CANstate==0? 255 : 0);
}

void APPprintCANmsg(CAN_msg_t &msg) {
  Serial.print("id=");  Serial.println(msg.id);
  Serial.print("data=");  Serial.println(msg.data[8]);
  Serial.print("len=");  Serial.println(msg.len);
  //Serial.print("ch=");  Serial.println(msg.ch);
  Serial.print("format=");  Serial.println(msg.format);
  Serial.print("type=");  Serial.println(msg.type);
}

void APPreadCAN() {
  if(!CANbus.available()) return;

  //Serial.println("available ");
  //Serial.println();

  CAN_msg_t inbound;
  CANbus.receive(&inbound);
  //APPprintCANmsg(inbound);

  uint16_t functionCode = COB_GET_FUNCTION_CODE(inbound.id);
  if(functionCode == COB_SDO_SEND) {
    //Serial.println("SDO Send");
    if(CANbus.CANBusAddress!=0) return;  // only root cares about receiving messages.

    int index = COB_GET_ADDRESS(inbound.id);  // from who?
    if(index<0 || index>=NUM_AXIES) return;

    //Serial.print("address ");
    //Serial.println(index);

    uint8_t i=0;
    uint16_t id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) {
        APPtoggleCANState();
        lastHeard[index] = CAN_GET_FLOAT(inbound,i) * 360.0;
        //Serial.print("receive one position ");
        //Serial.print(index);
        //Serial.print("=");
        //Serial.println(lastHeard[index]);
      }
    }
  } else if( functionCode == COB_SDO_RECEIVE) {
    //Serial.println("SDO Receive");
    int index = COB_GET_ADDRESS(inbound.id);  // for who?
    if(index != 0x7f && index != CANbus.CANBusAddress) return;  // not for everyone and not for me

    //Serial.println("For me");

    uint8_t i=0;
    int id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      APPtoggleCANState();
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) APPsendSensor();
    } else if( id == CAN_SET ) {
      //Serial.print("set ");
      uint8_t subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_SET_POSITION) {
        APPtoggleCANState();
        //Serial.print("position ");
        MOTORsetTargetPosition(CAN_GET_FLOAT(inbound,i));
        //Serial.print(targetPosition);
      } else if(subIndex == CAN_SET_VELOCITY) {
        APPtoggleCANState();
        MOTORsetTargetVelocity(CAN_GET_FLOAT(inbound,i));
      }
      //Serial.println();
    }
  }
}


void APPsendSensor() {
  //Serial.println("APPsendSensor");
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
    //Serial.println("APPrequestOnePosition myself");
    lastHeard[index] = sensorAngleUnit * 360.0;
  } else {
    //Serial.print("APPrequestOnePosition ");
    //Serial.println(index);
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_RECEIVE,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ);
    CAN_ADD_SHORT(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ_POSITION);
    CANbus.send(&CAN_TX_msg);
  }
}

void APPrequestAllPositions2() {
  lastHeard[0] = sensorAngleUnit * 360.0;
  APPrequestOnePosition(ADDRESS_EVERYONE);
}

void APPrequestAllPositions1() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    APPrequestOnePosition(i);
  }
}

void APPrequestAllPositions() {
  APPrequestAllPositions1();
}

/**
 * @param index which joint to move
 * @param v 0...1
 */
void APPsendOnePosition(int index,float v) {
  if(index==0 && CANbus.CANBusAddress==0) {
    //Serial.print("APPsendOnePosition myself ");
    //Serial.println(v);
    MOTORsetTargetPosition(v);
  } else {
    //Serial.print("APPsendOnePosition ");
    //Serial.print(index);
    //Serial.print(' ');
    //Serial.println(v);
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_RECEIVE,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_SET);
    CAN_ADD_SHORT(CAN_TX_msg,CAN_SET_POSITION);
    CAN_ADD_FLOAT(CAN_TX_msg,v);
    CANbus.send(&CAN_TX_msg);
  }
}

/**
 * @param index which joint to move
 * @param v 0...1
 */
void APPsendOneVelocity(int index,float v) {
  if(index==0 && CANbus.CANBusAddress==0) {
    //Serial.print("APPsendOnePosition myself ");
    //Serial.println(v);
    velocityDegPerS = v;
    MOTORsetTargetVelocity(v);
  } else {
    //Serial.print("APPsendOnePosition ");
    //Serial.print(index);
    //Serial.print(' ');
    //Serial.println(v);
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_RECEIVE,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_SET);
    CAN_ADD_SHORT(CAN_TX_msg,CAN_SET_VELOCITY);
    CAN_ADD_FLOAT(CAN_TX_msg,v);
    CANbus.send(&CAN_TX_msg);
  }
}


void APPrapidMove() {
  Serial.println("APPrapidMove");
  // velocity
  int pos = seen('F');
  if(pos>=0) APPsetVelocity(atof(serialBufferIn+pos));
  
  // positions
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    pos = seen(axies[i]);
    if(pos>=0) {
      v = atof(serialBufferIn+pos);
      Serial.print(' ');
      Serial.print(axies[i]);
      Serial.print(v);
      v /= 360.0;
      nextPos[i] = v;
      APPsendOnePosition(i,v);
    }
  }

  Serial.print(' ');
  Serial.print('F');
  Serial.print(velocityDegPerS);
  Serial.println();
}


void APPreportAllMotorPositions() {
  Serial.print("M114");
  for(int i=0;i<NUM_AXIES;++i) {
    Serial.print(' ');
    Serial.print(axies[i]);
    Serial.print(lastHeard[i],2);
  }

  Serial.print(' ');
  Serial.print('F');
  Serial.print(velocityDegPerS);
  Serial.println();
}

void APPserverUpdate() {
  // only server at address 0
  if(CANbus.CANBusAddress!=0) return;
  
  // sometimes ask for position updates.
  uint32_t t = millis();
  if(t - lastReq > 1000) {
    lastReq=t;
    APPrequestAllPositions();
  }
}


void APPupdate() {
  APPreadCAN();
  APPserverUpdate();
}

void APPsetVelocity(float newVel) {
  for(int i=0;i<NUM_AXIES;++i) {
    APPsendOneVelocity(i,newVel);
  }
}