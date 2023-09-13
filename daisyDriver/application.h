#pragma once
//-----------------------------------------------------------------------------

#define NUM_AXIES (6)

#define ADDRESS_EVERYONE 0x7F  // 0b00001111111

#define POSITION_UPDATE_INTERVAL  100 // ms

//-----------------------------------------------------------------------------

uint8_t CANstate=0;

//-----------------------------------------------------------------------------

class Application {
public:
  void setup();
  void update();
  void toggleCANState();
  void rapidMove();
  void reportAllMotorPositions();

private:
  void printCANmsg(CAN_msg_t &msg);
  void readCAN();
  void sendSensor();
  void requestOnePosition(uint8_t index);
  void requestAllPositionsAtOnce();
  void requestAllPositionsIndividually();
  void requestAllPositions();
  void sendOnePosition(int index,float v);
  void sendOneVelocity(int index,float v);
  void serverUpdate();
  void setVelocity(float newVel);

  void setTargetPosition(float targetPosition);
  void setTargetVelocity(float targetVelocity);
};

extern Application application;
