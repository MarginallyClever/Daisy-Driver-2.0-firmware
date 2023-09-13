#include "config.h"
//-----------------------------------------------------------------------------

char axies[NUM_AXIES]  = {'X','Y','Z','U','V','W'};
float nextPos[NUM_AXIES];
float lastHeard[NUM_AXIES];
uint32_t lastReq=0;
float velocityDegPerS = 5;

Application application;

//-----------------------------------------------------------------------------

void Application::setup() {
  MOTORsetTargetVelocity(velocityDegPerS);
}

void Application::toggleCANState() {
  CANstate = (CANstate==0? 255 : 0);
}

void Application::printCANmsg(CAN_msg_t &msg) {
  Serial.print("id=");  Serial.println(msg.id);
  Serial.print("data=");  Serial.println(msg.data[8]);
  Serial.print("len=");  Serial.println(msg.len);
  //Serial.print("ch=");  Serial.println(msg.ch);
  Serial.print("format=");  Serial.println(msg.format);
  Serial.print("type=");  Serial.println(msg.type);
}

void Application::readCAN() {
  if(!CANbus.available()) return;

  CAN_msg_t inbound;
  CANbus.receive(&inbound);
  //printCANmsg(inbound);

  uint16_t functionCode = COB_GET_FUNCTION_CODE(inbound.id);
  //Serial.print("available ");
  //Serial.println(functionCode,HEX);

  if(functionCode == COB_SDO_SEND) {
    int index = COB_GET_ADDRESS(inbound.id);  // from who?

    //Serial.print("SDO send from ");
    //Serial.println(index);

    if(CANbus.myAddress!=0) return;  // only root cares about receiving messages.

    if(index<0 || index>=NUM_AXIES) return;


    uint8_t i=0;
    uint16_t id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) {
        toggleCANState();
        lastHeard[index] = CAN_GET_FLOAT(inbound,i) * 360.0;
        //Serial.print("receive one position ");
        //Serial.print(index);
        //Serial.print("=");
        //Serial.println(lastHeard[index]);
      }
    }
  } else if( functionCode == COB_SDO_RECEIVE) {
    int index = COB_GET_ADDRESS(inbound.id);  // for who?
    //Serial.print("SDO Receive ");
    //Serial.println(index);
    if(index != ADDRESS_EVERYONE && index != CANbus.myAddress) return;  // not for everyone and not for me

    //Serial.println("For me");

    uint8_t i=0;
    int id = CAN_GET_LONG(inbound,i);
    if( id == CAN_CUSTOM_PARAMETER_READ ) {
      toggleCANState();
      int subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_CUSTOM_PARAMETER_READ_POSITION) sendSensor();
    } else if( id == CAN_SET ) {
      uint8_t subIndex = CAN_GET_SHORT(inbound,i);
      if(subIndex == CAN_SET_POSITION) {
        setTargetPosition(CAN_GET_FLOAT(inbound,i));
      } else if(subIndex == CAN_SET_VELOCITY) {
        setTargetVelocity(CAN_GET_FLOAT(inbound,i));
      }
    }
  }
}

void Application::setTargetPosition(float targetPosition) {
  toggleCANState();
  Serial.print("set position ");
  Serial.println(targetPosition*360.0f);
  MOTORsetTargetPosition(targetPosition);
}

void Application::setTargetVelocity(float targetVelocity) {
  toggleCANState();
  Serial.print("set velocity ");
  Serial.println(targetVelocity);
  velocityDegPerS = targetVelocity;
  MOTORsetTargetVelocity(targetVelocity);
}

void Application::sendSensor() {
  //Serial.println("sendSensor");
  CAN_msg_t CAN_TX_msg;
  CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_SEND,CANbus.myAddress);
  CAN_START(CAN_TX_msg);
  CAN_ADD_LONG(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ);
  CAN_ADD_SHORT(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ_POSITION);
  CAN_ADD_FLOAT(CAN_TX_msg,sensorAngleUnit);
  CANbus.send(&CAN_TX_msg);
}

void Application::requestOnePosition(uint8_t index) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.println("requestOnePosition myself");
    lastHeard[index] = sensorAngleUnit * 360.0;
  } else {
    //Serial.print("requestOnePosition ");
    //Serial.println(index);
    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = MAKE_COB_ID(COB_SDO_RECEIVE,index);
    CAN_START(CAN_TX_msg);
    CAN_ADD_LONG(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ);
    CAN_ADD_SHORT(CAN_TX_msg,CAN_CUSTOM_PARAMETER_READ_POSITION);
    CANbus.send(&CAN_TX_msg);
  }
}

void Application::requestAllPositionsAtOnce() {
  lastHeard[0] = sensorAngleUnit * 360.0;
  requestOnePosition(ADDRESS_EVERYONE);
}

void Application::requestAllPositionsIndividually() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    requestOnePosition(i);
  }
}

void Application::requestAllPositions() {
  requestAllPositionsIndividually();
  //requestAllPositionsAtOnce();
}

/**
 * @param index which joint to move
 * @param v 0...1
 */
void Application::sendOnePosition(int index,float v) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.print("sendOnePosition myself ");
    //Serial.println(v);
    MOTORsetTargetPosition(v);
  } else {
    //Serial.print("sendOnePosition ");
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
void Application::sendOneVelocity(int index,float v) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.print("sendOnePosition myself ");
    //Serial.println(v);
    velocityDegPerS = v;
    MOTORsetTargetVelocity(velocityDegPerS);
  } else {
    //Serial.print("sendOnePosition ");
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


void Application::rapidMove() {
  Serial.println("rapidMove");
  // velocity
  int pos = seen('F');
  if(pos>=0) {
    setVelocity(atof(serialBufferIn+pos));
    // if this delay is too small the other unit doesn't receive the positions that follow.
    // 250 is too small.  500 works.  375 works.
    delay(375);
  }
  
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
      sendOnePosition(i,v);
    }
  }

  Serial.print(' ');
  Serial.print('F');
  Serial.print(velocityDegPerS);
  Serial.println();
}


void Application::reportAllMotorPositions() {
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

void Application::serverUpdate() {
  // only server at address 0
  if(CANbus.myAddress!=0) return;
  
  // sometimes ask for position updates.
  uint32_t t = millis();
  if(t - lastReq > 1000) {
    lastReq=t;
    requestAllPositions();
  }
}


void Application::update() {
  readCAN();
  serverUpdate();
}

void Application::setVelocity(float newVel) {
  for(int i=0;i<NUM_AXIES;++i) {
    sendOneVelocity(i,newVel);
  }
}