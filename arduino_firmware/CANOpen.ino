class CANOpen {
  static int functionCode;
  static int nodeAddress;

  static void parseCAN(CAN_msg_t *msg) {
    if(messageIsNotForMe(msg)) return;

  }

  static bool messageIsNotForMe(CAN_msg_t *msg) {
    int id = msg.id;
    functionCode = (id & 0b11110000000) >> 7;
    nodeAddress  = (id & 0b00001111111);
    return (nodeAddress == CANBusAddress || nodeAddress == 0b1111111);
  }
}