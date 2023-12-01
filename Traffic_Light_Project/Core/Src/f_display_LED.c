/*
 * f_display_LED.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */


#include "f_display_LED.h"

int horizontal_state = INIT;
int vertical_state = INIT;

void fsmHorLeds()
{
	switch (horizontal_state) {
		case INIT:
			horizontal_state = AUTO_RED;
			setTimer(0, RED_time);
			break;
		case AUTO_RED:
			if (isTimerUp(0))
			{
				horizontal_state = AUTO_GREEN;
				setTimer(0, RED_time);
			}
			break;
		case AUTO_GREEN:
			if(isTimerUp(0))
			{
				horizontal_state = AUTO_YELLOW;
				setTimer(0, GREEN_time);
			}
			break;
		case AUTO_YELLOW:
			if(isTimerUp(0))
			{
				horizontal_state = AUTO_RED;
				setTimer(0, RED_time);
			}
			break;
		default:
			break;
	}
}

void fsmVerLeds()
{
	switch (vertical_state) {
		case INIT:
			vertical_state = AUTO_GREEN;
			setTimer(1, GREEN_time);
			break;
		case AUTO_RED:
			if (isTimerUp(1))
			{
				vertical_state = AUTO_GREEN;
				setTimer(1, GREEN_time);
			}
			break;
		case AUTO_GREEN:
			if(isTimerUp(1))
			{
				vertical_state = AUTO_YELLOW;
				setTimer(1, YELLOW_time);
			}
			break;
		case AUTO_YELLOW:
			if(isTimerUp(1))
			{
				vertical_state = AUTO_RED;
				setTimer(1, RED_time);
			}
			break;
		default:
			break;
	}
}

void displayLeds()
{
	fsmHorLeds();
	fsmVerLeds();

	switch (horizontal_state) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_OFF);
			break;

		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_ON);
			break;

		default:
			break;
	}

	switch (vertical_state) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_OFF);
			break;

		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_ON);
			break;
		default:
			break;
	}
}

void resetLight()
{
	horizontal_state = INIT;
	vertical_state = INIT;
}
