#include "config.h"
//-----------------------------------------------------------------------------

char axies[NUM_AXIES]  = {'X','Y','Z','U','V','W'};
float nextPos[NUM_AXIES];
float lastHeard[NUM_AXIES];
uint32_t lastReq=0;

Server server;

//-----------------------------------------------------------------------------

void Server::setup() {
  delay(1500);
  requestAllReset();
}

void Server::toggleCANState() {
  //CANstate = (CANstate==0? 255 : 0);
}

/**
 * Attempt to read from the CAN network.  If anything is found, process it.
 */
void Server::readCAN() {
  if(!CANbus.available()) return;
  
  CANParser inbound;
  CANbus.receive(&inbound.canMsg);
  //inbound.print();

  if(inbound.getFunctionCode() == COB_SDO_RECEIVE) {
    parseReceive(inbound);
  } else{
    Serial.print(F("Server unknown function code "));
    Serial.println(inbound.getFunctionCode());
  }
}

// Someone has replied to a request.
void Server::parseReceive(CANParser &inbound) {
  if(CANbus.myAddress!=0) return;  // only server can receive.

  int index = inbound.getAddress();  // from who?
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


/**
 * Send one float value response
 * @param subIndex the subindex code
 * @param value the float
 */
void Server::replyOneFloat(uint8_t subIndex,float value) {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(subIndex);
  msg.addFloat(value);
  msg.send();
}

/**
 * Send one short value response
 * @param subIndex the subindex code
 * @param value the short
 */
void Server::replyOneShort(uint8_t subIndex,uint8_t value) {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(subIndex);
  msg.addShort(value);
  msg.send();
}

/**
 * request sensor angle from node with id=index
 * @param index the id of the node being asked.
 */
void Server::requestOneSensor(uint8_t index) {
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

void Server::requestAllSensorsAtOnce() {
  lastHeard[0] = sensorAngleUnit * 360.0;
  requestOneSensor(ADDRESS_EVERYONE);
}

void Server::requestAllSensorsIndividually() {
  float v;
  for(int i=0;i<NUM_AXIES;++i) {
    requestOneSensor(i);
  }
}

void Server::requestAllSensors() {
  requestAllSensorsIndividually();
  //requestAllSensorsAtOnce();
}

/**
 * @param index which joint to move
 * @param v 0...1
 */
void Server::sendOnePosition(int index,float v) {
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
void Server::sendOneVelocity(int index,float v) {
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


void Server::rapidMove() {
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


void Server::reportAllMotorPositions() {
  Serial.print("M114");

  requestAllSensors();
  long t = millis()+250;
  while(millis()<t) readCAN();

  for(int i=0;i<NUM_AXIES;++i) {
    Serial.print(' ');
    Serial.print(axies[i]);
    Serial.print(lastHeard[i],2);
  }

  Serial.println();
}

/**
 * Ask every node to report their ID.
 */
void Server::requestAllNodeIDs() {
  CANParser msg;
  msg.start(COB_SDO_SEND,ADDRESS_EVERYONE);
  msg.addLong(CAN_READ);
  msg.addShort(CAN_ID);
  msg.send();
}

void Server::requestAllReset() {
  CANParser msg;
  msg.start(COB_SDO_SEND,ADDRESS_EVERYONE);
  msg.addLong(CAN_SET);
  msg.addShort(CAN_RESET);
  msg.send();
}


void Server::serverUpdate() {
  // only server at address 0
  if(CANbus.myAddress!=0) return;
  
  // sometimes ask for position updates.
  uint32_t t = millis();
  if(t - lastReq > POSITION_UPDATE_INTERVAL) {
    lastReq=t;
    requestAllSensors();
  }

  if(CANbus.receiveOverflow(CAN_ACTIVE_CHANNEL,1)) {
    Serial.println("overflow 1");
  }
  if(CANbus.receiveOverflow(CAN_ACTIVE_CHANNEL,2)) {
    Serial.println("overflow 2");
  }
}


void Server::update() {
  readCAN();
  serverUpdate();
}

void Server::setAllVelocity(float newVel) {
  for(int i=0;i<NUM_AXIES;++i) {
    sendOneVelocity(i,newVel);
  }
}

void Server::enableOneMotor(uint8_t index,bool newState) {
  if(index==CANbus.myAddress) {
    motor.enable(newState);
  } else {
    CANParser msg;
    msg.start(COB_SDO_SEND,index);
    msg.addLong(CAN_SET);
    msg.addShort(CAN_ENABLE_MOTOR);
    msg.addShort(newState);
    msg.send();
  }
}

void Server::enableAllMotors(bool newState) {
  motor.enable(newState);

  CANParser msg;
  msg.start(COB_SDO_SEND,ADDRESS_EVERYONE);
  msg.addLong(CAN_SET);
  msg.addShort(CAN_ENABLE_MOTOR);
  msg.addShort(newState);
  msg.send();
}
