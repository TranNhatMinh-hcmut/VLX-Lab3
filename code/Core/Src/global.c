/*
 * global.c
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */
#include "global.h"

// Gan cac chan vat ly cho khoi chuc nang

GPIO_7SEG_Config output_7Seg[7] = {
		{a_GPIO_Port, a_Pin},
		{b_GPIO_Port, b_Pin},
		{c_GPIO_Port, c_Pin},
		{d_GPIO_Port, d_Pin},
		{e_GPIO_Port, e_Pin},
		{f_GPIO_Port, f_Pin},
		{g_GPIO_Port, g_Pin},
};

/*----------------------- Quet LED 7SEG -----------------------*/

uint16_t buffer_7Seg[NUM_7SEG];

GPIO_Config Enable_7Seg[NUM_7SEG] = {
		{EN0_GPIO_Port, EN0_Pin},
		{EN1_GPIO_Port, EN1_Pin},
		{EN2_GPIO_Port, EN2_Pin},
		{EN3_GPIO_Port, EN3_Pin}
};

uint8_t index_EN = NUM_7SEG; // Trang thai khoi tao

void update_buffer_7Seg(uint16_t value1, uint16_t value2) {
//	if(value1 > 99) value1 = 1;
//	else if(value1 < 1) value1 = 99;
//
//	if(value2 > 99) value2 = 3;
//	else if(value2 < 3) value2 = 99;

	uint16_t n[4];
	n[0] = value1 / 10;
	n[1] = value1 - (n[0] * 10);
	n[2] = value2 / 10;
	n[3] = value2 - (n[2] * 10);
	for(uint8_t i = 0; i < 4; i++) {
		buffer_7Seg[i] = n[i];
	}
}

/*--------------------- END Quet LED 7SEG --------------------*/

/*-------------- Traffic light -----------------*/

STATUS status_traffic_light = INIT;

uint16_t time_of_color[NUM_COLOR] = {5,2,3};
uint16_t default_time_of_color[NUM_COLOR] = {5,2,3};

GPIO_Config Traffic_Light1[NUM_COLOR] = {
		{red1_GPIO_Port, red1_Pin},
		{yellow1_GPIO_Port, yellow1_Pin},
		{green1_GPIO_Port, green1_Pin}
};

GPIO_Config Traffic_Light2[NUM_COLOR] = {
		{red2_GPIO_Port, red2_Pin},
		{yellow2_GPIO_Port, yellow2_Pin},
		{green2_GPIO_Port, green2_Pin},
};

/*-------------- END Traffic light -----------------*/

STATUS status_mode = NORMAL;

