/*
 * Quet_LED7Seg.c
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#include "Quet_LED7Seg.h"

uint16_t time_of_each_7Seg = 50;

void clear_all_EN() {
	for(uint8_t i = 0; i < NUM_7SEG; i++) {
		HAL_GPIO_WritePin(Enable_7Seg[i].Port, Enable_7Seg[i].Pin, GPIO_PIN_SET);
	}
}

void Quet_7Seg_run() {

		switch(index_EN) {
			case NUM_7SEG:
				clear_all_EN();
				display7SEG(-1); // Tat 7seg
				index_EN = 0;
//				time_of_each_7Seg = CY_7SEG / NUM_7SEG;
				setTimer(1, time_of_each_7Seg);
				break;
			case 0:
				HAL_GPIO_WritePin(Enable_7Seg[NUM_7SEG - 1].Port, Enable_7Seg[NUM_7SEG - 1].Pin, GPIO_PIN_SET);
				display7SEG(buffer_7Seg[0]);
				HAL_GPIO_WritePin(Enable_7Seg[0].Port, Enable_7Seg[0].Pin, GPIO_PIN_RESET);

				if(is_flag_set(1)) {
					index_EN = 1;
					setTimer(1, time_of_each_7Seg);
				}
				break;
			case 1:
				HAL_GPIO_WritePin(Enable_7Seg[0].Port, Enable_7Seg[0].Pin, GPIO_PIN_SET);
				display7SEG(buffer_7Seg[1]);
				HAL_GPIO_WritePin(Enable_7Seg[1].Port, Enable_7Seg[1].Pin, GPIO_PIN_RESET);

				if(is_flag_set(1)) {
					index_EN = 2;
					setTimer(1, time_of_each_7Seg);
				}
				break;
			case 2:
				HAL_GPIO_WritePin(Enable_7Seg[1].Port, Enable_7Seg[1].Pin, GPIO_PIN_SET);
				display7SEG(buffer_7Seg[2]);
				HAL_GPIO_WritePin(Enable_7Seg[2].Port, Enable_7Seg[2].Pin, GPIO_PIN_RESET);

				if(is_flag_set(1)) {
					index_EN = 3;
					setTimer(1, time_of_each_7Seg);
				}
				break;
			case 3:
				HAL_GPIO_WritePin(Enable_7Seg[2].Port, Enable_7Seg[2].Pin, GPIO_PIN_SET);
				display7SEG(buffer_7Seg[3]);
				HAL_GPIO_WritePin(Enable_7Seg[3].Port, Enable_7Seg[3].Pin, GPIO_PIN_RESET);

				if(is_flag_set(1)) {
					index_EN++;
					if(index_EN >= NUM_7SEG)
						index_EN = 0;
					setTimer(1, time_of_each_7Seg);
				}
				break;
			default:
				clear_all_EN();
				break;
		}

}
