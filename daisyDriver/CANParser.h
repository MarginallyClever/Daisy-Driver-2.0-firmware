#pragma once
/**
 * CANParser reads and writes valid CANbus messages.
 * @author Dan Royer
 * @since 2023-09-26
 */
class CANParser {
public:
  CAN_msg_t canMsg;
  int index=0;

  void start(uint16_t functionCode,uint16_t address) {
    canMsg.format = STANDARD_FORMAT;
    canMsg.type = DATA_FRAME;
    canMsg.len = 0;
    canMsg.id = MAKE_COB_ID(functionCode,address);
  }

  inline uint16_t getFunctionCode() {
    return COB_GET_FUNCTION_CODE(canMsg.id);
  }

  inline uint16_t getAddress() {
    return COB_GET_ADDRESS(canMsg.id);
  }

  inline void addShort(uint8_t v) {
    canMsg.data[canMsg.len++] = ((v)&0xFF);
  }

  inline uint8_t getShort() {
    return canMsg.data[index++];
  }

  inline void addLong(long v) {
    addShort((v >> 8) & 0xFF);
    addShort((v     ) & 0xFF);
  }

  inline uint16_t getLong() {
    return ((uint16_t)getShort() << 8) | ((uint16_t)getShort());
  }

  inline void addFloat(float v) {
    uint8_t* samesies = (uint8_t*)&(v);
    addShort(samesies[3]);
    addShort(samesies[2]);
    addShort(samesies[1]);
    addShort(samesies[0]);
  }

  inline float getFloat() {
    uint32_t i = ((uint32_t)getShort() << 24) 
               | ((uint32_t)getShort() << 16) 
               | ((uint32_t)getShort() << 8) 
               | ((uint32_t)getShort());
    float r = *(float*)&i;
    return r;
  }

  void print() {
    Serial.print("id="    );  Serial.println(canMsg.id);
    Serial.print("data="  );  Serial.println(canMsg.data[8]);
    Serial.print("len="   );  Serial.println(canMsg.len);
    //Serial.print("ch="    );  Serial.println(canMsg.ch);
    Serial.print("format=");  Serial.println(canMsg.format);
    Serial.print("type="  );  Serial.println(canMsg.type);
  }

  inline void send() {
    CANbus.send(&canMsg);
  }
};