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
  void requestAllNodeIDs();
  bool iAmMaster();

  /**
   * Enable or disable one motor.
   * @param index which motor
   * @param newState true to enable, false to disable.
   */
  void enableOneMotor(uint8_t index,bool newState);

  /**
   * Enable or disable one motor.
   * @params newState true to enable, false to disable.
   */
  void enableAllMotors(bool newState);

private:
  void printCANmsg(CAN_msg_t &msg);
  void readCAN();
  void sendID();
  void replyOneFloat(uint8_t subIndex,float value);
  void replyOneShort(uint8_t subIndex,uint8_t value);
  void requestOneSensor(uint8_t index);
  void requestAllSensorsAtOnce();
  void requestAllSensorsIndividually();
  void requestAllSensors();
  void sendOnePosition(int index,float v);
  void sendOneVelocity(int index,float v);

  void serverUpdate();
  void setAllVelocity(float newVel);

  void setTargetPosition(float targetPosition);
  void setTargetVelocity(float targetVelocity);

  void parseReceive(CANParser &inbound);
  void parseSend(CANParser &inbound);
};

extern Application application;
