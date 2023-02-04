//-----------------------------------------------------------------------------
// CAN bus for Daisy Driver
// from https://github.com/nopnop2002/Arduino-STM32-CAN/tree/master/stm32f103
//-----------------------------------------------------------------------------
#include "CANBus.h"
#include <assert.h>

char CANBusAddress;

// Calculation of bit timing dependent on peripheral clock rate
int16_t CANComputeTimings(const uint32_t peripheral_clock_rate,
                          const uint32_t target_bitrate,
                          CAN_bit_timing_config_t* const out_timings) {
    if (target_bitrate < 1000)
    {
        return -CAN_STM32_ERROR_UNSUPPORTED_BIT_RATE;
    }

    assert(out_timings != NULL);  // NOLINT
    memset(out_timings, 0, sizeof(*out_timings));

    // Hardware configuration
    static const uint8_t MaxBS1 = 16;
    static const uint8_t MaxBS2 = 8;

    /**
     * Ref. "Automatic Baudrate Detection in CANopen Networks", U. Koppe, MicroControl GmbH & Co. KG
     *     CAN in Automation, 2003
     *
     * According to the source, optimal quanta per bit are:
     *   Bitrate        Optimal Maximum
     *   1000 kbps      8       10
     *   500  kbps      16      17
     *   250  kbps      16      17
     *   125  kbps      16      17
     */
    const uint8_t max_quanta_per_bit = (uint8_t)((target_bitrate >= 1000000) ? 10 : 17);    // NOLINT
    assert(max_quanta_per_bit <= (MaxBS1 + MaxBS2));

    static const uint16_t MaxSamplePointLocationPermill = 900;

    /**
     * Computing (prescaler * BS):
     *   BITRATE = 1 / (PRESCALER * (1 / PCLK) * (1 + BS1 + BS2))       -- See the Reference Manual
     *   BITRATE = PCLK / (PRESCALER * (1 + BS1 + BS2))                 -- Simplified
     * let:
     *   BS = 1 + BS1 + BS2                                             -- Number of time quanta per bit
     *   PRESCALER_BS = PRESCALER * BS
     * ==>
     *   PRESCALER_BS = PCLK / BITRATE
     */
    const uint32_t prescaler_bs = peripheral_clock_rate / target_bitrate;

    // Searching for such prescaler value so that the number of quanta per bit is highest.
    uint8_t bs1_bs2_sum = (uint8_t)(max_quanta_per_bit - 1);    // NOLINT

    while ((prescaler_bs % (1U + bs1_bs2_sum)) != 0)
    {
        if (bs1_bs2_sum <= 2)
        {
            return -CAN_STM32_ERROR_UNSUPPORTED_BIT_RATE;          // No solution
        }
        bs1_bs2_sum--;
    }

    const uint32_t prescaler = prescaler_bs / (1U + bs1_bs2_sum);
    if ((prescaler < 1U) || (prescaler > 1024U))
    {
        return -CAN_STM32_ERROR_UNSUPPORTED_BIT_RATE;              // No solution
    }

    /**
     * Now we have a constraint: (BS1 + BS2) == bs1_bs2_sum.
     * We need to find such values so that the sample point is as close as possible to the optimal value,
     * which is 87.5%, which is 7/8.
     *
     *   Solve[(1 + bs1)/(1 + bs1 + bs2) == 7/8, bs2]  (* Where 7/8 is 0.875, the recommended sample point location *)
     *   {{bs2 -> (1 + bs1)/7}}
     *
     * Hence:
     *   bs2 = (1 + bs1) / 7
     *   bs1 = (7 * bs1_bs2_sum - 1) / 8
     *
     * Sample point location can be computed as follows:
     *   Sample point location = (1 + bs1) / (1 + bs1 + bs2)
     *
     * Since the optimal solution is so close to the maximum, we prepare two solutions, and then pick the best one:
     *   - With rounding to nearest
     *   - With rounding to zero
     */
    uint8_t bs1 = (uint8_t)(((7 * bs1_bs2_sum - 1) + 4) / 8);       // Trying rounding to nearest first  // NOLINT
    uint8_t bs2 = (uint8_t)(bs1_bs2_sum - bs1);  // NOLINT
    assert(bs1_bs2_sum > bs1);

    {
        const uint16_t sample_point_permill = (uint16_t)(1000U * (1U + bs1) / (1U + bs1 + bs2));  // NOLINT

        if (sample_point_permill > MaxSamplePointLocationPermill)   // Strictly more!
        {
            bs1 = (uint8_t)((7 * bs1_bs2_sum - 1) / 8);             // Nope, too far; now rounding to zero
            bs2 = (uint8_t)(bs1_bs2_sum - bs1);
        }
    }

    const bool valid = (bs1 >= 1) && (bs1 <= MaxBS1) && (bs2 >= 1) && (bs2 <= MaxBS2);

    /**
     * Final validation
     * Helpful Python:
     * def sample_point_from_btr(x):
     *     assert 0b0011110010000000111111000000000 & x == 0
     *     ts2,ts1,brp = (x>>20)&7, (x>>16)&15, x&511
     *     return (1+ts1+1)/(1+ts1+1+ts2+1)
     */
    if ((target_bitrate != (peripheral_clock_rate / (prescaler * (1U + bs1 + bs2)))) ||
        !valid)
    {
        // This actually means that the algorithm has a logic error, hence assert(0).
        assert(0);  // NOLINT
        return -CAN_STM32_ERROR_UNSUPPORTED_BIT_RATE;
    }

    out_timings->baud_rate_prescaler = (uint16_t) prescaler;
    out_timings->resynchronization_jump_width = 1;      // One is recommended by UAVCAN, CANOpen, and DeviceNet
    out_timings->time_segment_1 = bs1;
    out_timings->time_segment_2 = bs2;

    #ifdef CAN_DEBUG
      DEBUG("target_bitrate=");
      DEBUGLN(target_bitrate);
      DEBUG("peripheral_clock_rate=");
      DEBUGLN(peripheral_clock_rate);
  
      DEBUG("timings.baud_rate_prescaler=");
      DEBUGLN(out_timings->baud_rate_prescaler);
      DEBUG("timings.time_segment_1=");
      DEBUGLN(out_timings->time_segment_1);
      DEBUG("timings.time_segment_2=");
      DEBUGLN(out_timings->time_segment_2);
      DEBUG("timings.resynchronization_jump_width=");
      DEBUGLN(out_timings->resynchronization_jump_width);
    #endif
    return 0;
}
 
// Print registers.
void CANPrintRegister(const char * buf, uint32_t reg) {
  #ifdef CAN_DEBUG
  DEBUG(buf);
  DEBUG(reg, HEX);
  DEBUGLN();
  #endif
}

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
 *
 */
void CANSetFilter(uint8_t index, uint8_t scale, uint8_t mode, uint8_t fifo, uint32_t bank1, uint32_t bank2) {
  if (index > 27) return;

  CAN1->FA1R &= ~(0x1UL<<index);               // Deactivate filter

  if (scale == 0) {
    CAN1->FS1R &= ~(0x1UL<<index);             // Set filter to Dual 16-bit scale configuration
  } else {
    CAN1->FS1R |= (0x1UL<<index);              // Set filter to single 32 bit configuration
  }
    if (mode == 0) {
    CAN1->FM1R &= ~(0x1UL<<index);             // Set filter to Mask mode
  } else {
    CAN1->FM1R |= (0x1UL<<index);              // Set filter to List mode
  }

  if (fifo == 0) {
    CAN1->FFA1R &= ~(0x1UL<<index);            // Set filter assigned to FIFO 0
  } else {
    CAN1->FFA1R |= (0x1UL<<index);             // Set filter assigned to FIFO 1
  }

  CAN1->sFilterRegister[index].FR1 = bank1;    // Set filter bank registers1
  CAN1->sFilterRegister[index].FR2 = bank2;    // Set filter bank registers2

  CAN1->FA1R |= (0x1UL<<index);                // Activate filter

}

/**
 * Initializes the CAN controller with specified bit rate.
 *
 * @params: bitrate - Specified bitrate. If this value is not one of the defined constants, bit rate will be defaulted to 125KBS
 * @params: remap   - Select CAN port. 
 *                    =0:CAN_RX mapped to PA11, CAN_TX mapped to PA12
 *                    =1:Not used
 *                    =2:CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)
 *                    =3:CAN_RX mapped to PD0, CAN_TX mapped to PD1 (available on 100-pin and 144-pin package)
 *
 */
bool CANInit(BITRATE bitrate, int remap) {
  // Reference manual
  // https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf

  RCC->APB1ENR |= 0x2000000UL;       // Enable CAN clock 
  RCC->APB2ENR |= 0x1UL;             // Enable AFIO clock
  AFIO->MAPR   &= 0xFFFF9FFF;        // reset CAN remap
                                     // CAN_RX mapped to PA11, CAN_TX mapped to PA12

  if (remap == 0) {
    RCC->APB2ENR |= 0x4UL;           // Enable GPIOA clock
    GPIOA->CRH   &= ~(0xFF000UL);    // Configure PA12(0b0000) and PA11(0b0000)
                                     // 0b0000
                                     //   MODE=00(Input mode)
                                     //   CNF=00(Analog mode)

    GPIOA->CRH   |= 0xB8FFFUL;       // Configure PA12(0b1011) and PA11(0b1000)
                                     // 0b1011
                                     //   MODE=11(Output mode, max speed 50 MHz) 
                                     //   CNF=10(Alternate function output Push-pull
                                     // 0b1000
                                     //   MODE=00(Input mode)
                                     //   CNF=10(Input with pull-up / pull-down)
                                     
    GPIOA->ODR |= 0x1UL << 12;       // PA12 Upll-up
    
  }
                                
  if (remap == 2) {
    AFIO->MAPR   |= 0x00004000;      // set CAN remap
                                     // CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)

    RCC->APB2ENR |= 0x8UL;           // Enable GPIOB clock
    GPIOB->CRH   &= ~(0xFFUL);       // Configure PB9(0b0000) and PB8(0b0000)
                                     // 0b0000
                                     //   MODE=00(Input mode)
                                     //   CNF=00(Analog mode)

    GPIOB->CRH   |= 0xB8UL;          // Configure PB9(0b1011) and PB8(0b1000)
                                     // 0b1011
                                     //   MODE=11(Output mode, max speed 50 MHz) 
                                     //   CNF=10(Alternate function output Push-pull
                                     // 0b1000
                                     //   MODE=00(Input mode)
                                     //   CNF=10(Input with pull-up / pull-down)
                                     
    GPIOB->ODR |= 0x1UL << 8;        // PB8 Upll-up
  }
  
  if (remap == 3) {
    AFIO->MAPR   |= 0x00005000;      // set CAN remap
                                     // CAN_RX mapped to PD0, CAN_TX mapped to PD1 (available on 100-pin and 144-pin package)

    RCC->APB2ENR |= 0x20UL;          // Enable GPIOD clock
    GPIOD->CRL   &= ~(0xFFUL);       // Configure PD1(0b0000) and PD0(0b0000)
                                     // 0b0000
                                     //   MODE=00(Input mode)
                                     //   CNF=00(Analog mode)

    GPIOD->CRH   |= 0xB8UL;          // Configure PD1(0b1011) and PD0(0b1000)
                                     // 0b1000
                                     //   MODE=00(Input mode)
                                     //   CNF=10(Input with pull-up / pull-down)
                                     // 0b1011
                                     //   MODE=11(Output mode, max speed 50 MHz) 
                                     //   CNF=10(Alternate function output Push-pull
                                     
    GPIOD->ODR |= 0x1UL << 0;        // PD0 Upll-up
  }

  CAN1->MCR |= 0x1UL;                   // Require CAN1 to Initialization mode 
  while (!(CAN1->MSR & 0x1UL));         // Wait for Initialization mode

  //CAN1->MCR = 0x51UL;                 // Hardware initialization(No automatic retransmission)
  CAN1->MCR = 0x41UL;                   // Hardware initialization(With automatic retransmission)
   
  // Set bit timing register 
  CAN_bit_timing_config_t timings;
  DEBUG("bitrate=");
  DEBUGLN(bitrate);
  uint32_t target_bitrate = SPEED[bitrate];
  DEBUG("target_bitrate=");
  DEBUGLN(target_bitrate);
  int result = CANComputeTimings(HAL_RCC_GetPCLK1Freq(), target_bitrate, &timings);
  DEBUG("CANComputeTimings result=");
  DEBUGLN(result);
  if (result) while(true);  
  CAN1->BTR = (((timings.resynchronization_jump_width - 1U) &    3U) << 24U) |
              (((timings.time_segment_1 - 1U)               &   15U) << 16U) |
              (((timings.time_segment_2 - 1U)               &    7U) << 20U) |
              ((timings.baud_rate_prescaler - 1U)           & 1023U);

  // Configure Filters to default values
  CAN1->FMR  |=   0x1UL;                // Set to filter initialization mode
  CAN1->FMR  &= 0xFFFFC0FF;             // Clear CAN2 start bank

  // bxCAN has 28 filters.
  // These filters are shared by both CAN1 and CAN2.
  // STM32F103 has only CAN1, so all 28 are used for CAN1
  CAN1->FMR  |= 0x1C << 8;              // Assign all filters to CAN1

  // Set fileter 0
  // Single 32-bit scale configuration 
  // Two 32-bit registers of filter bank x are in Identifier Mask mode
  // Filter assigned to FIFO 0 
  // Filter bank register to all 0
  CANSetFilter(0, 1, 0, 0, 0x0UL, 0x0UL); 
  
  CAN1->FMR   &= ~(0x1UL);              // Deactivate initialization mode

  uint16_t TimeoutMilliseconds = 1000;
  bool can1 = false;
  CAN1->MCR   &= ~(0x1UL);              // Require CAN1 to normal mode 

  // Wait for normal mode
  // If the connection is not correct, it will not return to normal mode.
  for (uint16_t wait_ack = 0; wait_ack < TimeoutMilliseconds; wait_ack++) {
    if ((CAN1->MSR & 0x1UL) == 0) {
      can1 = true;
      break;
    }
    delayMicroseconds(1000);
  }
  //DEBUG("can1=");
  //DEBUGLN(can1);
  if (can1) {
    DEBUGLN("CAN1 initialize ok");
  } else {
    DEBUGLN("CAN1 initialize fail!!");
    return false;
  }
  return true; 
}
 
/**
 * Decodes CAN messages from the data registers and populates a 
 * CAN message struct with the data fields.
 * 
 * @preconditions A valid CAN message is received
 * @params CAN_rx_msg - CAN message structure for reception
 * 
 */
void CANReceive(CAN_msg_t* CAN_rx_msg)
{
  uint32_t id = CAN1->sFIFOMailBox[0].RIR;
  if ((id & STM32_CAN_RIR_IDE) == 0) { // Standard frame format
      CAN_rx_msg->format = STANDARD_FORMAT;;
      CAN_rx_msg->id = (CAN_STD_ID_MASK & (id >> 21U));
  } 
  else {                               // Extended frame format
      CAN_rx_msg->format = EXTENDED_FORMAT;;
      CAN_rx_msg->id = (CAN_EXT_ID_MASK & (id >> 3U));
  }

  if ((id & STM32_CAN_RIR_RTR) == 0) { // Data frame
      CAN_rx_msg->type = DATA_FRAME;
  }
  else {                               // Remote frame
      CAN_rx_msg->type = REMOTE_FRAME;
  }

  
  CAN_rx_msg->len = (CAN1->sFIFOMailBox[0].RDTR) & 0xFUL;
  
  CAN_rx_msg->data[0] = 0xFFUL &  CAN1->sFIFOMailBox[0].RDLR;
  CAN_rx_msg->data[1] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDLR >> 8);
  CAN_rx_msg->data[2] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDLR >> 16);
  CAN_rx_msg->data[3] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDLR >> 24);
  CAN_rx_msg->data[4] = 0xFFUL &  CAN1->sFIFOMailBox[0].RDHR;
  CAN_rx_msg->data[5] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDHR >> 8);
  CAN_rx_msg->data[6] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDHR >> 16);
  CAN_rx_msg->data[7] = 0xFFUL & (CAN1->sFIFOMailBox[0].RDHR >> 24);

  // Release FIFO 0 output mailbox.
  // Make the next incoming message available.
  CAN1->RF0R |= 0x20UL;
}
 
/**
 * Encodes CAN messages using the CAN message struct and populates the 
 * data registers with the sent.
 * 
 * @params CAN_tx_msg - CAN message structure for transmission
 * 
 */
void CANSend(CAN_msg_t* CAN_tx_msg) {
  volatile int count = 0;

  uint32_t out = 0;
  if (CAN_tx_msg->format == EXTENDED_FORMAT) { // Extended frame format
      out = ((CAN_tx_msg->id & CAN_EXT_ID_MASK) << 3U) | STM32_CAN_TIR_IDE;
  }
  else {                                       // Standard frame format
      out = ((CAN_tx_msg->id & CAN_STD_ID_MASK) << 21U);
  }

  // Remote frame
  if (CAN_tx_msg->type == REMOTE_FRAME) {
      out |= STM32_CAN_TIR_RTR;
  }

  CAN1->sTxMailBox[0].TDTR &= ~(0xF);
  CAN1->sTxMailBox[0].TDTR |= CAN_tx_msg->len & 0xFUL;
  
  CAN1->sTxMailBox[0].TDLR  = (((uint32_t) CAN_tx_msg->data[3] << 24) |
                               ((uint32_t) CAN_tx_msg->data[2] << 16) |
                               ((uint32_t) CAN_tx_msg->data[1] <<  8) |
                               ((uint32_t) CAN_tx_msg->data[0]      ));
  CAN1->sTxMailBox[0].TDHR  = (((uint32_t) CAN_tx_msg->data[7] << 24) |
                               ((uint32_t) CAN_tx_msg->data[6] << 16) |
                               ((uint32_t) CAN_tx_msg->data[5] <<  8) |
                               ((uint32_t) CAN_tx_msg->data[4]      ));

  // Send Go
  CAN1->sTxMailBox[0].TIR = out | STM32_CAN_TIR_TXRQ;

  // Wait until the mailbox is empty
  while(CAN1->sTxMailBox[0].TIR & 0x1UL && count++ < 1000000);

  // The mailbox don't becomes empty while loop
  if (CAN1->sTxMailBox[0].TIR & 0x1UL) {
    DEBUGLN("Send Fail");
    DEBUGLN(CAN1->ESR);
    DEBUGLN(CAN1->MSR);
    DEBUGLN(CAN1->TSR);
  }
}

/**
 * Returns whether there are CAN messages available.
 *
 * @returns If pending CAN messages are in the CAN controller
 *
 */
uint8_t CANMsgAvail(void) {
  // Check for pending FIFO 0 messages
  return CAN1->RF0R & 0x3UL;
}


void CANdemo() {
  uint8_t counter = 0;
  uint8_t frameLength = 0;
  unsigned long previousMillis = 0;     // stores last time output was updated
  const long interval = 1000;           // transmission interval (milliseconds)

  CAN_msg_t CAN_TX_msg;
  CAN_msg_t CAN_RX_msg;

  CAN_TX_msg.len = frameLength;
  CAN_TX_msg.data[0] = 0x00;
  CAN_TX_msg.data[1] = 0x01;
  CAN_TX_msg.data[2] = 0x02;
  CAN_TX_msg.data[3] = 0x03;
  CAN_TX_msg.data[4] = 0x04;
  CAN_TX_msg.data[5] = 0x05;
  CAN_TX_msg.data[6] = 0x06;
  CAN_TX_msg.data[7] = 0x07;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if ( ( counter % 2) == 0) {
      CAN_TX_msg.type = DATA_FRAME;
      if (CAN_TX_msg.len == 0) CAN_TX_msg.type = REMOTE_FRAME;
      CAN_TX_msg.format = EXTENDED_FORMAT;
      CAN_TX_msg.id = 0x32F103;
    } else {
      CAN_TX_msg.type = DATA_FRAME;
      if (CAN_TX_msg.len == 0) CAN_TX_msg.type = REMOTE_FRAME;
      CAN_TX_msg.format = STANDARD_FORMAT;
      CAN_TX_msg.id = 0x103;
    }
    CANSend(&CAN_TX_msg);
    frameLength = (frameLength+1)%9;
    counter++;
  }
  
  if(CANMsgAvail()) {
    CANReceive(&CAN_RX_msg);

    if (CAN_RX_msg.format == EXTENDED_FORMAT) {
      DEBUG("Extended ID: 0x");
      if (CAN_RX_msg.id < 0x10000000) DEBUG("0");
      if (CAN_RX_msg.id < 0x1000000) DEBUG("00");
      if (CAN_RX_msg.id < 0x100000) DEBUG("000");
      if (CAN_RX_msg.id < 0x10000) DEBUG("0000");
      DEBUG2(CAN_RX_msg.id, HEX);
    } else {
      DEBUG("Standard ID: 0x");
      if (CAN_RX_msg.id < 0x100) DEBUG("0");
      if (CAN_RX_msg.id < 0x10) DEBUG("00");
      DEBUG2(CAN_RX_msg.id, HEX);
      DEBUG("     ");
    }

    DEBUG(" DLC: ");
    DEBUG(CAN_RX_msg.len);
    if (CAN_RX_msg.type == DATA_FRAME) {
      DEBUG(" Data: ");
      for(int i=0; i<CAN_RX_msg.len; i++) {
        DEBUG("0x"); 
        DEBUG2(CAN_RX_msg.data[i], HEX); 
        if (i != (CAN_RX_msg.len-1))  DEBUG(" ");
      }
      DEBUGLN();
    } else {
      DEBUGLN(" Data: REMOTE REQUEST FRAME");
    }
  }
}


#ifdef BUILD_CANBUS
void CANsetup() {
  DEBUGLN(F("CANsetup()"));
  LEDsetColor(0,0,0);

  pinMode(PIN_CAN_SILENT,OUTPUT);
  digitalWrite(PIN_CAN_SILENT,LOW);

  bool ret = CANInit(CAN_SPEED, 2);  // CAN_RX mapped to PB8, CAN_TX mapped to PB9
  if(ret) {
    DEBUGLN(F("CANsetup OK"));
    LEDsetColor(0,255,0);
  } else {
    DEBUGLN(F("CANsetup FAILED"));
    LEDsetColor(255,0,0);
  }
}


unsigned long previousMillis = 0;     // stores last time output was updated
long count=0;

void CANstep() {
  CANwriteTest();
  CANreadTest();
}


void CANreadTest() {
  if(CANMsgAvail()) {
    CAN_msg_t CAN_RX_msg;
    CANReceive(&CAN_RX_msg);
  }
}

void CANwriteTest() {
  unsigned long currentMillis = millis();
  const long interval = 100;           // transmission interval (milliseconds)

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    count = (count+1)%2;
    if(count==1)  LEDsetColor(0,0,255);
    else          LEDsetColor(0,255,0);

    CAN_msg_t CAN_TX_msg;
    CAN_TX_msg.id = (0x1<<7) + CANBusAddress;
    CAN_TX_msg.format = STANDARD_FORMAT;
    CAN_TX_msg.type = DATA_FRAME;
    CAN_TX_msg.len = 4;
    int32_t *samesies = (int32_t*)&sensorAngle;
    CAN_TX_msg.data[0] = samesies[0];
    CAN_TX_msg.data[1] = samesies[1];
    CAN_TX_msg.data[2] = samesies[2];
    CAN_TX_msg.data[3] = samesies[3];
    CANSend(&CAN_TX_msg);
  }
}
#endif