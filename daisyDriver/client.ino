#include "config.h"
//-----------------------------------------------------------------------------

float velocityDegPerS = 5;

Client client;

//-----------------------------------------------------------------------------

void Client::setup() {
  motor.setTargetVelocity(velocityDegPerS);
  // I just joined the party.  Hi!  My name is...
  delay(CANbus.myAddress * CAN_ADDRESS_EVERYONE_DELAY);
  sendID();
}

void Client::toggleCANState() {
  //CANstate = (CANstate==0? 255 : 0);
}

/**
 * Attempt to read from the CAN network.  If anything is found, process it.
 */
void Client::readCAN() {
  if(!CANbus.available()) return;
  
  CANParser inbound;
  CANbus.receive(&inbound.canMsg);
  //inbound.print();

  if(inbound.getFunctionCode()==COB_SDO_SEND) {
    parseSend(inbound);
  } else {
    Serial.print(F("Client unknown function code "));
    Serial.println(inbound.getFunctionCode());
  }
}

// master node has requested read/write
void Client::parseSend(CANParser &inbound) {
  int index = inbound.getAddress();  // for/from who?

  if(index == ADDRESS_EVERYONE) {
    // if every board receives this message at the same time and responds at the same time it can flood the server's inbox.
    // if all boards delay some fixed equal value, same problem.  therefore use this board's unique CAN address as a scalar for the delay time
    // so they take turns.
    delay(CANbus.myAddress*CAN_ADDRESS_EVERYONE_DELAY);
  } else if(index != CANbus.myAddress) {
    return;  // not for everyone and not for me
  }  

  toggleCANState();
  int id = inbound.getLong();
  uint8_t subIndex = inbound.getShort();

  if(id == CAN_READ) {
    switch(subIndex) {
      case CAN_ID: sendID();  break;
      case CAN_POSITION: replyOneFloat(CAN_POSITION,motor.getTargetPosition());  break;
      case CAN_VELOCITY: replyOneFloat(CAN_VELOCITY,velocityDegPerS);  break;
      case CAN_SENSOR: replyOneFloat(CAN_SENSOR,sensorAngleUnit);  break;
      case CAN_ENABLE_MOTOR:  replyOneShort(CAN_ENABLE_MOTOR,motor.getMotorEnable());  break;
      default:  break;
    }
  } else if(id == CAN_SET) {
    switch(subIndex) {
      case CAN_ID:  break;  // do nothing.
      case CAN_POSITION:  setTargetPosition(inbound.getFloat());  break;
      case CAN_VELOCITY:  setTargetVelocity(inbound.getFloat());  break;
      case CAN_SENSOR:  break;  // do nothing.
      case CAN_ENABLE_MOTOR:  motor.enable(inbound.getShort());  break;
      case CAN_RESET:  HAL_NVIC_SystemReset();  break;
      default:  break;
    }
  }
}

void Client::setTargetPosition(float targetPosition) {
  toggleCANState();
  Serial.print("set position ");
  Serial.println(targetPosition*360.0f);
  motor.setTargetPosition(targetPosition);
}

void Client::setTargetVelocity(float targetVelocity) {
  toggleCANState();
  Serial.print("set velocity ");
  Serial.println(targetVelocity);
  velocityDegPerS = targetVelocity;
  motor.setTargetVelocity(targetVelocity);
}

/**
 * Send CANBus ID of this node.
 */
void Client::sendID() {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(CAN_ID);
  msg.addShort(CANbus.myAddress);
  msg.send();
}

/**
 * Send one float value response
 * @param subIndex the subindex code
 * @param value the float
 */
void Client::replyOneFloat(uint8_t subIndex,float value) {
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
void Client::replyOneShort(uint8_t subIndex,uint8_t value) {
  CANParser msg;
  msg.start(COB_SDO_RECEIVE,CANbus.myAddress);
  msg.addLong(CAN_READ);
  msg.addShort(subIndex);
  msg.addShort(value);
  msg.send();
}

void Client::update() {
  readCAN();
}