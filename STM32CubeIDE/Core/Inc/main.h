/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TMC_SKIP_Pin GPIO_PIN_13
#define TMC_SKIP_GPIO_Port GPIOC
#define TMC_STALL_Pin GPIO_PIN_14
#define TMC_STALL_GPIO_Port GPIOC
#define TMC_SPI_MODE_Pin GPIO_PIN_15
#define TMC_SPI_MODE_GPIO_Port GPIOC
#define CAN_ADDR0_Pin GPIO_PIN_0
#define CAN_ADDR0_GPIO_Port GPIOC
#define CAN_ADDR1_Pin GPIO_PIN_1
#define CAN_ADDR1_GPIO_Port GPIOC
#define CAN_ADDR2_Pin GPIO_PIN_2
#define CAN_ADDR2_GPIO_Port GPIOC
#define CAN_ADDR3_Pin GPIO_PIN_3
#define CAN_ADDR3_GPIO_Port GPIOC
#define ADC_IPS_COS_Pin GPIO_PIN_0
#define ADC_IPS_COS_GPIO_Port GPIOA
#define ADC_IPS_COSN_Pin GPIO_PIN_1
#define ADC_IPS_COSN_GPIO_Port GPIOA
#define ADC_IPS_SIN_Pin GPIO_PIN_2
#define ADC_IPS_SIN_GPIO_Port GPIOA
#define ADC_IPS_SINN_Pin GPIO_PIN_3
#define ADC_IPS_SINN_GPIO_Port GPIOA
#define CAN_ADDR4_Pin GPIO_PIN_4
#define CAN_ADDR4_GPIO_Port GPIOC
#define CAN_ADDR5_Pin GPIO_PIN_5
#define CAN_ADDR5_GPIO_Port GPIOC
#define TMC_DIR_Pin GPIO_PIN_12
#define TMC_DIR_GPIO_Port GPIOB
#define TMC_STEP_Pin GPIO_PIN_13
#define TMC_STEP_GPIO_Port GPIOB
#define TMC_EN_Pin GPIO_PIN_14
#define TMC_EN_GPIO_Port GPIOB
#define TMC_STEP_GATE_Pin GPIO_PIN_15
#define TMC_STEP_GATE_GPIO_Port GPIOB
#define PWM_TMC_CURRSET_Pin GPIO_PIN_6
#define PWM_TMC_CURRSET_GPIO_Port GPIOC
#define PWM_RGB_G_Pin GPIO_PIN_7
#define PWM_RGB_G_GPIO_Port GPIOC
#define PWM_RGB_R_Pin GPIO_PIN_8
#define PWM_RGB_R_GPIO_Port GPIOC
#define PWM_RGB_B_Pin GPIO_PIN_9
#define PWM_RGB_B_GPIO_Port GPIOC
#define SWD_CLK_Pin GPIO_PIN_14
#define SWD_CLK_GPIO_Port GPIOA
#define TMC_STEP_RDY_Pin GPIO_PIN_15
#define TMC_STEP_RDY_GPIO_Port GPIOA
#define SWD_SWO_Pin GPIO_PIN_3
#define SWD_SWO_GPIO_Port GPIOB
#define CAN_SILENT_Pin GPIO_PIN_5
#define CAN_SILENT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
