/*
 * f_display_LED.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#ifndef INC_F_DISPLAY_LED_H_
#define INC_F_DISPLAY_LED_H_

#include "f_global.h"
#include "f_timer.h"
#include "main.h"

extern int horizontal_state;
extern int vertical_state;

void displayLeds();
void resetLight();

#endif /* INC_F_DISPLAY_LED_H_ */
