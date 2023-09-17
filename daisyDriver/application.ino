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
  motor.setTargetVelocity(velocityDegPerS);
  if(iAmMaster()) {
    delay(1500);
    requestAllNodeIDs();
  }
}

bool Application::iAmMaster() {
  return CANbus.myAddress==0;
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

  switch(inbound.getFunctionCode()) {
    case COB_SDO_RECEIVE:  parseReceive(inbound);  break;
    case COB_SDO_SEND:  parseSend(inbound);  break;
    default:  break;
  }
}

// Someone has replied to a request.
void Application::parseReceive(CANParser &inbound) {
  if(CANbus.myAddress!=0) return;  // only root can receive.

  int index = inbound.getAddress();  // from who?
  if(index<0 || index>=NUM_AXIES) return;  // invalid address?!

  uint16_t id = inbound.getLong();
  if(id == CAN_READ) {
    toggleCANState();
    int subIndex = inbound.getShort();
    if(subIndex == CAN_SENSOR) {
      lastHeard[index] = inbound.getFloat() * 360.0;
      //Serial.print("receive one position ");
      //Serial.print(index);
      //Serial.print("=");
      //Serial.println(lastHeard[index]);
    } else if(subIndex == CAN_ID) {
      Serial.print("CAN ID: ");
      Serial.println(inbound.getShort());
    }
  }
}


// master node has requested read/write
void Application::parseSend(CANParser &inbound) {
  int index = inbound.getAddress();  // for/from who?
  if(index != ADDRESS_EVERYONE && index != CANbus.myAddress) return;  // not for everyone and not for me
  //Serial.println("For me");

  toggleCANState();
  int id = inbound.getLong();
  uint8_t subIndex = inbound.getShort();

  if(id == CAN_READ) {
    switch(subIndex) {
      case CAN_ID: sendID();  break;
      case CAN_POSITION: replyOneFloat(CAN_POSITION,motor.getTargetPosition());  break;
      case CAN_VELOCITY: replyOneFloat(CAN_VELOCITY,velocityDegPerS);  break;
      case CAN_SENSOR: replyOneFloat(CAN_SENSOR,sensorAngleUnit);  break;
      default:  break;
    }
  } else if(id == CAN_SET) {
    switch(subIndex) {
      case CAN_ID:  break;  // do nothing.
      case CAN_POSITION:  setTargetPosition(inbound.getFloat());  break;
      case CAN_VELOCITY:  setTargetVelocity(inbound.getFloat());  break;
      case CAN_SENSOR:  break;  // do nothing.
      default:  break;
    }
  }
}

void Application::setTargetPosition(float targetPosition) {
  toggleCANState();
  Serial.print("set position ");
  Serial.println(targetPosition*360.0f);
  motor.setTargetPosition(targetPosition);
}

void Application::setTargetVelocity(float targetVelocity) {
  toggleCANState();
  Serial.print("set velocity ");
  Serial.println(targetVelocity);
  velocityDegPerS = targetVelocity;
  motor.setTargetVelocity(targetVelocity);
}

/**
 * Send CANBus ID of this node.
 */
void Application::sendID() {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(CAN_ID);
  msg.addShort(CANbus.myAddress);
  msg.send();
}

/**
 * Send one float response
 * @param subIndex the subindex code
 * @param value the float
 */
void Application::replyOneFloat(uint8_t subIndex,float value) {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(subIndex);
  msg.addFloat(value);
  msg.send();
}


/**
 * request sensor angle from node with id=index
 * @param index the id of the node being asked.
 */
void Application::requestOneSensor(uint8_t index) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.println("requestOnePosition myself");
    lastHeard[index] = sensorAngleUnit * 360.0;
  } else {
    //Serial.print("requestOnePosition ");
    //Serial.println(index);
    CANParser msg;
    msg.start(COB_SDO_SEND,index);
    msg.addLong(CAN_READ);
    msg.addShort(CAN_SENSOR);
    msg.send();
  }
}

void Application::requestAllSensorsAtOnce() {
  lastHeard[0] = sensorAngleUnit * 360.0;
  requestOneSensor(ADDRESS_EVERYONE);
}

void Application::requestAllSensorsIndividually() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    requestOneSensor(i);
  }
}

void Application::requestAllSensors() {
  requestAllSensorsIndividually();
  //requestAllSensorsAtOnce();
}

/**
 * @param index which joint to move
 * @param v 0...1
 */
void Application::sendOnePosition(int index,float v) {
  if(index==0 && CANbus.myAddress==0) {
    //Serial.print("sendOnePosition myself ");
    //Serial.println(v);
    motor.setTargetPosition(v);
  } else {
    //Serial.print("sendOnePosition ");
    //Serial.print(index);
    //Serial.print(' ');
    //Serial.println(v);
    CANParser msg;
    msg.start(COB_SDO_SEND,index);
    msg.addLong(CAN_SET);
    msg.addShort(CAN_POSITION);
    msg.addFloat(v);
    msg.send();
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
    motor.setTargetVelocity(velocityDegPerS);
  } else {
    //Serial.print("sendOnePosition ");
    //Serial.print(index);
    //Serial.print(' ');
    //Serial.println(v);
    CANParser msg;
    msg.start(COB_SDO_SEND,index);
    msg.addLong(CAN_SET);
    msg.addShort(CAN_VELOCITY);
    msg.addFloat(v);
    msg.send();
  }
}


void Application::rapidMove() {
  // velocity
  int pos = seen('F');
  if(pos>=0) {
    setAllVelocity(atof(serialBufferIn+pos));
    // if this delay is too small the other unit doesn't receive the positions that follow.
    // 250 is too small.  500 works.  375 works.
    //delay(375);
    Serial.print('F');
    Serial.print(velocityDegPerS);
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
  Serial.println();
}


void Application::reportAllMotorPositions() {
  Serial.print("M114");

  requestAllSensors();
  long t = millis()+250;
  while(millis()<t) readCAN();

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

/**
 * Ask every node to report their ID.
 */
void Application::requestAllNodeIDs() {
  CANParser msg;
  msg.start(COB_SDO_SEND,ADDRESS_EVERYONE);
  msg.addLong(CAN_READ);
  msg.addShort(CAN_ID);
  msg.send();
}

void Application::serverUpdate() {
  // only server at address 0
  if(CANbus.myAddress!=0) return;
  /*
  // sometimes ask for position updates.
  uint32_t t = millis();
  if(t - lastReq > POSITION_UPDATE_INTERVAL) {
    lastReq=t;
    requestAllSensors();
  }*/
}


void Application::update() {
  readCAN();
  serverUpdate();
}

void Application::setAllVelocity(float newVel) {
  for(int i=0;i<NUM_AXIES;++i) {
    sendOneVelocity(i,newVel);
  }
}