#pragma once
//-----------------------------------------------------------------------------
// CAN bus for Daisy Driver
// from https://github.com/nopnop2002/Arduino-STM32-CAN/blob/master/stm32f407/stm32f407.ino
//-----------------------------------------------------------------------------

// stm32f405 has two channels.  Valid values are 1 or 2
// Channel 1 is pins PB8/PB9, so that's the only good setting for this board.
#define CAN_ACTIVE_CHANNEL 1

// enable this and the app will wait for the mailbox to empty before returning.
#define CAN_CHECK_SEND_OK

// how long should the firmware wait for an outgoing mailbox to be available?
#define DEFAULT_MAILBOX_DELAY 10  //ms

//-----------------------------------------------------------------------------

// Symbolic names for bit rate of CAN message
typedef enum { CAN_50KBPS,
               CAN_100KBPS,
               CAN_125KBPS,
               CAN_250KBPS,
               CAN_500KBPS,
               CAN_1000KBPS
} BITRATE;

// Symbolic names for formats of CAN message
typedef enum {
  STANDARD_FORMAT = 0,
  EXTENDED_FORMAT
} CAN_FORMAT;

// Symbolic names for type of CAN message
typedef enum {
  DATA_FRAME = 0,
  REMOTE_FRAME
} CAN_FRAME;

//-----------------------------------------------------------------------------

#define CAN_STM32_ERROR_UNSUPPORTED_BIT_RATE 1000
#define CAN_STM32_ERROR_MSR_INAK_NOT_SET 1001
#define CAN_STM32_ERROR_MSR_INAK_NOT_CLEARED 1002
#define CAN_STM32_ERROR_UNSUPPORTED_FRAME_FORMAT 1003

#define STM32_CAN_TIR_TXRQ (1U << 0U)  // Bit 0: Transmit Mailbox Request
#define STM32_CAN_RIR_RTR (1U << 1U)   // Bit 1: Remote Transmission Request
#define STM32_CAN_RIR_IDE (1U << 2U)   // Bit 2: Identifier Extension
#define STM32_CAN_TIR_RTR (1U << 1U)   // Bit 1: Remote Transmission Request
#define STM32_CAN_TIR_IDE (1U << 2U)   // Bit 2: Identifier Extension

#define CAN_EXT_ID_MASK 0x1FFFFFFFU
#define CAN_STD_ID_MASK 0x000007FFU

//-----------------------------------------------------------------------------

#define MAKE_COB_ID(functionCode,address) (functionCode | address)
#define COB_GET_FUNCTION_CODE(cobID)      (cobID&0x780)  // 0b11110000000
#define COB_GET_ADDRESS(cobID)            (cobID&0x07F)  // 0b00001111111

//-----------------------------------------------------------------------------

typedef struct {
  uint32_t id;     /* 29 bit identifier                               */
  uint8_t data[8]; /* Data field                                      */
  uint8_t len;     /* Length of data field in bytes                   */
  uint8_t ch;      /* Object channel(Not use)                         */
  uint8_t format;  /* 0 - STANDARD, 1- EXTENDED IDENTIFIER            */
  uint8_t type;    /* 0 - DATA FRAME, 1 - REMOTE FRAME                */
} CAN_msg_t;

typedef const struct {
  uint8_t TS2;
  uint8_t TS1;
  uint8_t BRP;
} CAN_bit_timing_config_t;

//-----------------------------------------------------------------------------
class CANBus {
private:
  /**
    * Initializes the CAN GPIO registers.
    *
    * @params: addr    - Specified GPIO register address.
    * @params: index   - Specified GPIO index.
    * @params: speed   - Specified OSPEEDR register value.(Optional)
    *
    */
  void setGpio(GPIO_TypeDef* addr, uint8_t index, uint8_t speed = 3);

  // Calculation of bit timing dependent on peripheral clock rate
  int16_t computeTimings(const uint32_t peripheral_clock_rate,
                         const uint32_t target_bitrate,
                         CAN_bit_timing_config_t* const out_timings);

  // Print registers.
  void printRegister(const char* buf, uint32_t reg);

  /**
    * Initializes the CAN filter registers.
    *
    * @preconditions   - This register can be written only when the filter initialization mode is set (FINIT=1) in the CAN_FMR register.
    * @params: index   - Specified filter index. index 27:14 are available in connectivity line devices only.
    * @params: scale   - Select filter scale.
    *                    0: Dual 16-bit scale configuration
    *                    1: Single 32-bit scale configuration
    * @params: mode    - Select filter mode.
    *                    0: Two 32-bit registers of filter bank x are in Identifier Mask mode
    *                    1: Two 32-bit registers of filter bank x are in Identifier List mode
    * @params: fifo    - Select filter assigned.
    *                    0: Filter assigned to FIFO 0
    *                    1: Filter assigned to FIFO 1
    * @params: bank1   - Filter bank register 1
    * @params: bank2   - Filter bank register 2
    */
  void setFilter(uint8_t index, uint8_t scale, uint8_t mode, uint8_t fifo, uint32_t bank1, uint32_t bank2);

  /**
     * Returns whether there are CAN messages available.
     *
     * @param channel 1 or 2
     * @returns If pending CAN messages are in the CAN controller
     */
  uint8_t available(uint8_t channel, uint8_t fifoIndex);

  /**
   * @param channel 1 or 2
   * @return the index of the first FIFO buffer with data ready, or -1.
   */
  int8_t getFirstWaitingFIFOIndex(uint8_t channel);

  /**
    * Decodes CAN messages from the data registers and populates a 
    * CAN message struct with the data fields.
    * 
    * @preconditions A valid CAN message is received
    * @param channel 1 or 2
    * @param CAN_rx_msg - CAN message structure for reception
    */
  void receive(uint8_t channel, CAN_msg_t* CAN_rx_msg, uint8_t fifoIndex);

  /**
     * Encodes CAN messages using the CAN message struct and populates the 
     * data registers with the sent.
     * 
     * @param ch channel 1 or 2
     * @param CAN_tx_msg - CAN message structure for transmission
     */
  bool send(uint8_t ch, CAN_msg_t* CAN_tx_msg);

  /**
     * Returns whether there are CAN messages available.
     * @param channel 1 or 2
     * @returns If pending CAN messages are in the CAN controller
     */
  int8_t getFirstOutgoingAvailableMailbox(uint8_t channel);

  /**
     * Hang until a mailbox becomes available on this CAN channel.  
     * @See {getFirstOutgoingAvailableMailbox}
     * @param channel 1 or 2
     * @param maxDelay ms delay
     * @return boxes are 0,1,2 for either CAN channel.  -1 means no mailbox available.
     */
  int8_t waitForOutgoingAvailableMailbox(uint8_t channel, long maxDelay);

public:
  // my CAN node id.
  uint8_t myAddress;

  /**
    * Initializes the CAN controller with specified bit rate.
    *
    * @params: bitrate - Specified bitrate. If this value is not one of the defined constants, bit rate will be defaulted to 125KBS
    * @params: remap   - Select CAN port. 
    *                    =0:CAN_RX mapped to PA11, CAN_TX mapped to PA12
    *                    =1:Not used
    *                    =2:CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)
    *                    =3:CAN_RX mapped to PD0, CAN_TX mapped to PD1 (available on 100-pin and 144-pin package)
    */
  bool init(BITRATE bitrate, int remap);

  /**
    * Decodes CAN messages from the data registers and populates a 
    * CAN message struct with the data fields.
    * 
    * @preconditions A valid CAN message is received
    * @param CAN_rx_msg - CAN message structure for reception
    */
  void receive(CAN_msg_t* CAN_rx_msg);

  /**
    * Encodes CAN messages using the CAN message struct and populates the 
    * data registers with the sent.
    * 
    * @param CAN_tx_msg - CAN message structure for transmission
    */
  bool send(CAN_msg_t* CAN_tx_msg);

  /**
     * @returns If pending CAN messages are in the CAN controller
     */
  uint8_t available();

  inline int8_t getFirstOutgoingAvailableMailbox() {
    return getFirstOutgoingAvailableMailbox(CAN_ACTIVE_CHANNEL);
  }

  inline int8_t waitForOutgoingAvailableMailbox(long maxDelay) {
    return waitForOutgoingAvailableMailbox(CAN_ACTIVE_CHANNEL, maxDelay);
  }

  void readAddress();
  void setup();

  void stepTest();
  void readTest();
  void writeTest();
};

//-----------------------------------------------------------------------------

extern CANBus CANbus;

//-----------------------------------------------------------------------------

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