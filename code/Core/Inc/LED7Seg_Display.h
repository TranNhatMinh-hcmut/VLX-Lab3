/*
 * LED7Seg_Display.h
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#ifndef INC_LED7SEG_DISPLAY_H_
#define INC_LED7SEG_DISPLAY_H_

#include "main.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "stm32f1xx.h" // stm32 f1


typedef struct {
	GPIO_TypeDef* Port; // Port GPIO
	uint16_t Pin;		// Pin GPIO
} GPIO_7SEG_Config;


void Led7Seg_int(GPIO_7SEG_Config GPIO_Config[7]);
void display7SEG(int num);


#endif /* INC_LED7SEG_DISPLAY_H_ */
