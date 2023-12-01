/*
 * fsm_manual_mod.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#include "fsm_manual_mode.h"

void fsmManualModeRun()
{
	switch (mode) {
		case MANU_MODE:
			mode = MANU_RED;
			break;

		case MANU_RED:
			// Turn on red lights
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);

			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);

			// Switch to MAN_GREEN when press SET button
			if (isButtonPressed(BUTTON_SET))
			{
				mode = MANU_GREEN;
			}

			// Switch to TUNING MODE when press MODE button

			if(isButtonPressed(BUTTON_MODE))
			{
				mode = INC_RED;
				time_count = RED_time / 1000;
			}
			break;

		case MANU_GREEN:
			// Turn on green lights
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);

			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);

			// Switch to MAN_YELLOW when press SET button
			if (isButtonPressed(BUTTON_SET))
			{
				mode = MANU_YELLOW;
			}

			// Switch to TUNING MODE when press MODE button

			if(isButtonPressed(BUTTON_MODE))
			{
				mode = INC_GREEN;
				time_count = GREEN_time / 1000;
			}
			break;

		case MANU_YELLOW:
			// Turn on yellow lights
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);

			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);

			// Switch to MAN_RED when press SET button
			if (isButtonPressed(BUTTON_SET))
			{
				mode = MANU_RED;
			}

			// Switch to TUNING MODE when press MODE button

			if(isButtonPressed(BUTTON_MODE))
			{
				mode = INC_YELLOW;
				time_count = YELLOW_time / 1000;
			}
			break;

		default:
			break;
	}
}
