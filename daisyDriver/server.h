#pragma once
/**
 * The device with CAN id 0 is the server.
 */
class Server {
public:
  void setup();
  void update();
  void toggleCANState();
  void rapidMove();
  void reportAllMotorPositions();
  void requestAllNodeIDs();
  void requestAllReset();

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

  void parseReceive(CANParser &inbound);
};

//-----------------------------------------------------------------------------

extern Server server;
extern char axies[NUM_AXIES];
