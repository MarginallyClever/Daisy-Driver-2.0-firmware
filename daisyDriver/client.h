#pragma once
/**
 * Every device on the CAN network is a client.  Clients should never interact with Serial.
 */
class Client {
public:
  void setup();
  void update();
  void toggleCANState();

private:
  void readCAN();
  void sendID();
  void replyOneFloat(uint8_t subIndex,float value);
  void replyOneShort(uint8_t subIndex,uint8_t value);
  void requestOneSensor(uint8_t index);

  void serverUpdate();
  void setAllVelocity(float newVel);

  void setTargetPosition(float targetPosition);
  void setTargetVelocity(float targetVelocity);

  void parseSend(CANParser &inbound);
};

//-----------------------------------------------------------------------------

extern Client client;
