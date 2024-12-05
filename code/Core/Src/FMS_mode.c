/*
 * FMS_normal_mode.c
 *
 *  Created on: Nov 12, 2024
 *      Author: LEGION
 */

#include "FMS_mode.h"

uint16_t current_value = 0;

void FMS_mode_run() {

	switch(status_mode) {
		case NORMAL:
			TrafficLight_run();

			isButtonPressed(1);
			isButtonLongPressed(1);
			isButtonPressed(2);
			isButtonLongPressed(2);

			if(isButtonPressed(0)) {
				turn_off_traffic_light();
				current_value = time_of_color[red];
				status_mode = SET_RED;
				setTimer(2, 500);
			}

			break;
		case SET_RED:
			if(is_flag_set(2)) {
				HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
				HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
				setTimer(2, 500);
			}

			if(isButtonPressed(1))
				current_value++;
			if(isButtonLongPressed(1))
				current_value--;

			if(isButtonPressed(2))
				set_time_value(red, current_value);

			update_buffer_7Seg(current_value, SET_RED);

			if(isButtonPressed(0)) {
				HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);

				current_value = time_of_color[yellow];
				status_mode = SET_YELLOW;
				setTimer(2, 500);
			}
			break;

		case SET_YELLOW:
			if(is_flag_set(2)) {
				HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
				HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
				setTimer(2, 500);
			}

			if(isButtonPressed(1))
				current_value++;
			if(isButtonLongPressed(1))
				current_value--;

			if(isButtonPressed(2))
				set_time_value(yellow, current_value);

			update_buffer_7Seg(current_value, SET_YELLOW);

			if(isButtonPressed(0)) {
				HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);

				current_value = time_of_color[green];
				status_mode = SET_GREEN;
				setTimer(2, 500);
			}
			break;

		case SET_GREEN:
			if(is_flag_set(2)) {
				HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
				HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
				setTimer(2, 500);
			}

			if(isButtonPressed(1))
				current_value++;
			if(isButtonLongPressed(1))
				current_value--;

			if(isButtonPressed(2))
				set_time_value(green, current_value);

			update_buffer_7Seg(current_value, SET_GREEN);

			if(isButtonPressed(0)) {
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);

				status_mode = NORMAL;
				status_traffic_light = INIT;
			}
			break;

		default:
			break;
	}

	Quet_7Seg_run();
}
