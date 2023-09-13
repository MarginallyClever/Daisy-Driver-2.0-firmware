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

/**
 * Attempt to read from the CAN network.  If anything is found, process it.
 */
void Application::readCAN() {
  if(!CANbus.available()) return;

  CANParser inbound;
  CANbus.receive(&inbound.canMsg);
  //inbound.print();

  uint16_t functionCode = COB_GET_FUNCTION_CODE(inbound.canMsg.id);
  //Serial.print("available ");
  //Serial.println(functionCode,HEX);

  int index = COB_GET_ADDRESS(inbound.canMsg.id);  // for/from who?

  if(functionCode == COB_SDO_SEND) {
    // someone has sent a request to read or write to a node.
    //Serial.print("SDO send from ");
    //Serial.println(index);
    if(CANbus.myAddress!=0) return;  // only root can send.
    if(index<0 || index>=NUM_AXIES) return;

    uint16_t id = inbound.getLong();
    if( id == CAN_READ ) {
      int subIndex = inbound.getShort();
      if(subIndex == CAN_READ_POSITION) {
        toggleCANState();
        lastHeard[index] = inbound.getFloat() * 360.0;
        //Serial.print("receive one position ");
        //Serial.print(index);
        //Serial.print("=");
        //Serial.println(lastHeard[index]);
      }
    }
  } else if( functionCode == COB_SDO_RECEIVE) {
    // someone has responded to a request from another node.
    //Serial.print("SDO Receive ");
    //Serial.println(index);
    if(index != ADDRESS_EVERYONE && index != CANbus.myAddress) return;  // not for everyone and not for me
    //Serial.println("For me");

    int id = inbound.getLong();
    if( id == CAN_READ ) {
      toggleCANState();
      int subIndex = inbound.getShort();
      if(subIndex == CAN_READ_POSITION) sendSensor();
    } else if( id == CAN_SET ) {
      uint8_t subIndex = inbound.getShort();
      if(subIndex == CAN_SET_POSITION) {
        setTargetPosition(inbound.getFloat());
      } else if(subIndex == CAN_SET_VELOCITY) {
        setTargetVelocity(inbound.getFloat());
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
  CANParser msg;
  msg.start(COB_SDO_SEND,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(CAN_READ_POSITION);
  msg.addFloat(sensorAngleUnit);
  CANbus.send(&msg.canMsg);
}

void Application::requestOnePosition(uint8_t index) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.println("requestOnePosition myself");
    lastHeard[index] = sensorAngleUnit * 360.0;
  } else {
    //Serial.print("requestOnePosition ");
    //Serial.println(index);
    CANParser msg;
    msg.start(COB_SDO_RECEIVE,index);
    msg.addLong(CAN_READ);
    msg.addShort(CAN_READ_POSITION);
    CANbus.send(&msg.canMsg);
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
    CANParser msg;
    msg.start(COB_SDO_RECEIVE,index);
    msg.addLong(CAN_SET);
    msg.addShort(CAN_SET_POSITION);
    msg.addFloat(v);
    CANbus.send(&msg.canMsg);
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
    CANParser msg;
    msg.start(COB_SDO_RECEIVE,index);
    msg.addLong(CAN_SET);
    msg.addShort(CAN_SET_VELOCITY);
    msg.addFloat(v);
    CANbus.send(&msg.canMsg);
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
  if(t - lastReq > POSITION_UPDATE_INTERVAL) {
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