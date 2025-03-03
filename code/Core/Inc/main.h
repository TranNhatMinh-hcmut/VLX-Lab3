/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define a_Pin GPIO_PIN_1
#define a_GPIO_Port GPIOA
#define b_Pin GPIO_PIN_2
#define b_GPIO_Port GPIOA
#define c_Pin GPIO_PIN_3
#define c_GPIO_Port GPIOA
#define d_Pin GPIO_PIN_4
#define d_GPIO_Port GPIOA
#define e_Pin GPIO_PIN_5
#define e_GPIO_Port GPIOA
#define f_Pin GPIO_PIN_6
#define f_GPIO_Port GPIOA
#define g_Pin GPIO_PIN_7
#define g_GPIO_Port GPIOA
#define but0_Pin GPIO_PIN_0
#define but0_GPIO_Port GPIOB
#define but1_Pin GPIO_PIN_1
#define but1_GPIO_Port GPIOB
#define but2_Pin GPIO_PIN_2
#define but2_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_9
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_10
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_12
#define EN3_GPIO_Port GPIOA
#define led0_Pin GPIO_PIN_14
#define led0_GPIO_Port GPIOA
#define led1_Pin GPIO_PIN_15
#define led1_GPIO_Port GPIOA
#define red1_Pin GPIO_PIN_3
#define red1_GPIO_Port GPIOB
#define yellow1_Pin GPIO_PIN_4
#define yellow1_GPIO_Port GPIOB
#define green1_Pin GPIO_PIN_5
#define green1_GPIO_Port GPIOB
#define red2_Pin GPIO_PIN_6
#define red2_GPIO_Port GPIOB
#define yellow2_Pin GPIO_PIN_7
#define yellow2_GPIO_Port GPIOB
#define green2_Pin GPIO_PIN_8
#define green2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
