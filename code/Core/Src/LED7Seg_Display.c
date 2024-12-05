/*
 * LED7Seg_Display.c
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#include "LED7Seg_Display.h"


GPIO_7SEG_Config Led_7Seg_Array[7]; //// Array config port and pin

bool a, b, c, d, e, f, g;
uint8_t A, B, C, D;
uint8_t LED_4bit[] = {
			0b0000, //  0
			0b0001, //  1
			0b0010, //  2
			0b0011, //  3
			0b0100, //  4
			0b0101, //  5
			0b0110, //  6
			0b0111, //  7
			0b1000, //  8
			0b1001,  //  9
			0b1010 // tat
		};

void Led7Seg_int(GPIO_7SEG_Config GPIO_Config[7]){
	for (int i = 0; i < 7; i++) {
		Led_7Seg_Array[i] = GPIO_Config[i];
	}
}

void calculator_BCD_to_7SEG(int num){
	uint8_t  buffer;
	buffer = LED_4bit[num];

	// 4bit [3:0] -> [A:B]
	A = (buffer >> 3) & 1;
	B = (buffer >> 2) & 1;
	C = (buffer >> 1) & 1;
	D = (buffer >> 0) & 1;

	// f(ABCD)
	a = ((!B)&(!D)) | C | (B&D) | A;
	b = (!B) | ((!C)&(!D)) | (C&D);
	c = (!C) | D | B;
	d = ((!B)&(!D)) | ((!B)&C) | ((B&!C)&D) | (C&(!D)) | A;
	e = ((!B)&(!D)) | (C&(!D));
	f = ((!C)&(!D)) | (B&(!C)) | (B&(!D)) | A;
	g = ((!B)&C) | (B&(!C)) | A | (B&(!D));

}

void display7SEG(int num){
	if(num < 0 || num > 9)
		a = b = c = d = e = f = g = 0; //tat 7Seg
	else
		calculator_BCD_to_7SEG(num);

    HAL_GPIO_WritePin(Led_7Seg_Array[0].Port, Led_7Seg_Array[0].Pin, !a);
    HAL_GPIO_WritePin(Led_7Seg_Array[1].Port, Led_7Seg_Array[1].Pin, !b);
    HAL_GPIO_WritePin(Led_7Seg_Array[2].Port, Led_7Seg_Array[2].Pin, !c);
    HAL_GPIO_WritePin(Led_7Seg_Array[3].Port, Led_7Seg_Array[3].Pin, !d);
    HAL_GPIO_WritePin(Led_7Seg_Array[4].Port, Led_7Seg_Array[4].Pin, !e);
    HAL_GPIO_WritePin(Led_7Seg_Array[5].Port, Led_7Seg_Array[5].Pin, !f);
    HAL_GPIO_WritePin(Led_7Seg_Array[6].Port, Led_7Seg_Array[6].Pin, !g);
}
