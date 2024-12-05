/*
 * traffic_light.h
 *
 *  Created on: Nov 10, 2024
 *      Author: LEGION
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "global.h"
#include "Quet_LED7Seg.h"


void set_time_value(COLOR color, uint16_t new_time);
void turn_off_traffic_light();
void TrafficLight_run();


#endif /* INC_TRAFFIC_LIGHT_H_ */
