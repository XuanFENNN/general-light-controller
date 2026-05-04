/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define BATT_Pin GPIO_PIN_0
#define BATT_GPIO_Port GPIOA
#define MBT_Pin GPIO_PIN_1
#define MBT_GPIO_Port GPIOA
#define LEDT_Pin GPIO_PIN_2
#define LEDT_GPIO_Port GPIOA
#define VUSB_Pin GPIO_PIN_3
#define VUSB_GPIO_Port GPIOA
#define VBAT_Pin GPIO_PIN_4
#define VBAT_GPIO_Port GPIOA
#define FAN_SLEEP_Pin GPIO_PIN_2
#define FAN_SLEEP_GPIO_Port GPIOB
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define SPI2_WP_Pin GPIO_PIN_8
#define SPI2_WP_GPIO_Port GPIOA
#define EEP_WP_Pin GPIO_PIN_9
#define EEP_WP_GPIO_Port GPIOA
#define FAN1_Pin GPIO_PIN_10
#define FAN1_GPIO_Port GPIOA
#define FAN2_Pin GPIO_PIN_11
#define FAN2_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_12
#define KEY_GPIO_Port GPIOA
#define LEDOUT_Pin GPIO_PIN_15
#define LEDOUT_GPIO_Port GPIOA
#define K1_Pin GPIO_PIN_6
#define K1_GPIO_Port GPIOB
#define K2_Pin GPIO_PIN_7
#define K2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
