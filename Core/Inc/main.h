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
#define DLT_Pin GPIO_PIN_0
#define DLT_GPIO_Port GPIOA
#define MBT_Pin GPIO_PIN_1
#define MBT_GPIO_Port GPIOA
#define LEDT_Pin GPIO_PIN_2
#define LEDT_GPIO_Port GPIOA
#define FAN1_Pin GPIO_PIN_6
#define FAN1_GPIO_Port GPIOA
#define FAN2_Pin GPIO_PIN_7
#define FAN2_GPIO_Port GPIOA
#define RGB_Pin GPIO_PIN_11
#define RGB_GPIO_Port GPIOA
#define BTN_Pin GPIO_PIN_8
#define BTN_GPIO_Port GPIOB
#define BTN_EXTI_IRQn EXTI9_5_IRQn
#define LEDOUT_Pin GPIO_PIN_9
#define LEDOUT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
