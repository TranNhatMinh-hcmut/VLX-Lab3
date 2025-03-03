/*
 * button.h
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"


#define MAX_BUTTON 		3
#define TIME_OUT 		50
#define NORMAL_STATE 	SET
#define PRESSED_STATE 	RESET

//extern uint16_t button_flag[MAX_BUTTON];
//extern uint16_t button_long_pressed[MAX_BUTTON];

int isButtonPressed(int number);
int isButtonLongPressed(int number);

void init_button();
void getKeyInput();


#endif /* INC_BUTTON_H_ */
