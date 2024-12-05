/*
 * global.h
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>
#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "LED7Seg_Display.h"


typedef	uint8_t			STATUS;

typedef struct {
	GPIO_TypeDef* Port; // Port GPIO
	uint16_t Pin;		// Pin GPIO
} GPIO_Config;

extern GPIO_7SEG_Config output_7Seg[7];
/*-------------- Traffic light -----------------*/

typedef	uint8_t		COLOR;
#define	NUM_COLOR	3

#define red			0
#define	yellow		1
#define	green		2

// Traffic light state
#define INIT			0
#define green_red 		2
#define	yellow_red		3
#define	red_green		4
#define	red_yellow		5


extern STATUS status_traffic_light;
extern uint16_t time_of_color[NUM_COLOR];
extern uint16_t default_time_of_color[NUM_COLOR];
extern GPIO_Config Traffic_Light1[NUM_COLOR];
extern GPIO_Config Traffic_Light2[NUM_COLOR];

/*-------------- END Traffic light -----------------*/


/*----------------------- Quet LED 7SEG -----------------------*/

#define NUM_7SEG	4
#define CY_7SEG 	1000

extern uint16_t buffer_7Seg[NUM_7SEG];

extern GPIO_Config Enable_7Seg[NUM_7SEG];
extern uint8_t index_EN;

void update_buffer_7Seg(uint16_t value1, uint16_t value2);

/*--------------------- END Quet LED 7SEG --------------------*/


/*--------------------- FMS Mode --------------------*/

#define NORMAL		10
#define SET_RED		11
#define SET_YELLOW	12
#define SET_GREEN	13

extern STATUS status_mode;

/*--------------------- END FMS Mode --------------------*/
#endif /* INC_GLOBAL_H_ */
