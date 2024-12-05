/*
 * traffic_light.c
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */
#include "traffic_light.h"

uint16_t count_road1 = 0;
uint16_t count_road2 = 0;

void set_time_value(COLOR color, uint16_t new_time) {

	if(new_time > 99)
		new_time = default_time_of_color[color];
	else if(new_time < default_time_of_color[color])
		new_time = 99;

//	uint16_t old_time = time_of_color[color];
	if(color < NUM_COLOR)
		time_of_color[color] = new_time;

//	if(time_of_color[red] == time_of_color[yellow] + time_of_color[green]) return;
//
//	switch(color) {
//		case red:
//			time_of_color[yellow] = (	e) / old_time;
//			time_of_color[green] = new_time - time_of_color[yellow];
//			break;
//		case yellow:
//			time_of_color[red] = (time_of_color[red] * new_time) / old_time;
//			time_of_color[green] = time_of_color[red] - new_time;
//			break;
//		case green:
//			time_of_color[red] = (time_of_color[red] * new_time) / old_time;
//			time_of_color[yellow] = time_of_color[red] - new_time;
//			break;
//		default:
//			break;
//	}

}

void turn_off_traffic_light() {
	for(uint8_t i = 0; i < NUM_COLOR; i++) {
		HAL_GPIO_WritePin(Traffic_Light1[i].Port, Traffic_Light1[i].Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Traffic_Light2[i].Port, Traffic_Light2[i].Pin, GPIO_PIN_SET);
	}
}

void Turn_on_color(GPIO_Config LED[NUM_COLOR], COLOR color) {
	for(uint8_t i = 0; i < NUM_COLOR; i++) {
		if(i != color)
			HAL_GPIO_WritePin(LED[i].Port, LED[i].Pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(LED[color].Port, LED[color].Pin, GPIO_PIN_RESET);
}

void TrafficLight_run() {

	switch(status_traffic_light) {
		case INIT:
			// Den 1
			Turn_on_color(Traffic_Light1, green);
			// Den 2
			Turn_on_color(Traffic_Light2, red);
			status_traffic_light =	green_red;

			Led7Seg_int(output_7Seg);
			count_road1 = time_of_color[green] - 1;
			count_road2 = time_of_color[red] - 1;
			update_buffer_7Seg(count_road1, count_road2);

			setTimer(0, CY_7SEG);
			break;

		case green_red:
			// Den 1
			Turn_on_color(Traffic_Light1, green);
			// Den 2
			Turn_on_color(Traffic_Light2, red);

			if(is_flag_set(0)) {

				if(count_road1 > 0) {
					count_road1--;
					count_road2--;
				}
				else {
					count_road1 = time_of_color[yellow] - 1;
					count_road2--;
					status_traffic_light = yellow_red;
				}

				update_buffer_7Seg(count_road1, count_road2);

				setTimer(0, CY_7SEG);
			}
			break;

		case yellow_red:
			// Den 1
			Turn_on_color(Traffic_Light1, yellow);
			// Den 2
			Turn_on_color(Traffic_Light2, red);

			if(is_flag_set(0)) {

				if(count_road1 > 0) {
					count_road1--;
					count_road2--;
				}
				else {
					count_road1 = time_of_color[red] - 1;
					count_road2 = time_of_color[green] - 1;
					status_traffic_light = red_green;
				}
				update_buffer_7Seg(count_road1, count_road2);

				setTimer(0, CY_7SEG);
			}
			break;

		case red_green:
			// Den 1
			Turn_on_color(Traffic_Light1, red);
			// Den 2
			Turn_on_color(Traffic_Light2, green);

			if(is_flag_set(0)) {

				if(count_road2 > 0) {
					count_road1--;
					count_road2--;
				}
				else {
					count_road1--;
					count_road2 = time_of_color[yellow] - 1;
					status_traffic_light = red_yellow;
				}
				update_buffer_7Seg(count_road1, count_road2);

				setTimer(0, CY_7SEG);
			}
			break;

		case red_yellow:
			// Den 1
			Turn_on_color(Traffic_Light1, red);
			// Den 2
			Turn_on_color(Traffic_Light2, yellow);

			if(is_flag_set(0)) {

				if(count_road2 > 0) {
					count_road1--;
					count_road2--;
				}
				else {
					count_road1 = time_of_color[green] - 1;
					count_road2 = time_of_color[red] - 1;
					status_traffic_light = green_red;
				}
				update_buffer_7Seg(count_road1, count_road2);

				setTimer(0, CY_7SEG);
			}
			break;

		default:
			break;
	}
}


