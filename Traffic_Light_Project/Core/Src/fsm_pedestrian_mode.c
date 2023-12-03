/*
 * fsm_pedestrian_mode.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#include "fsm_pedestrian_mode.h"

int ver_ped = PED_OFF;
int hor_ped = PED_OFF;
int hor_buzzer_time = BUZZER_time_stop;
int hor_pul = BUZZER_pul_stop;
int hor_buzzer_state = BUZZER_OFF;
int ver_buzzer_time = BUZZER_time_stop;
int ver_pul = BUZZER_pul_stop;
int ver_buzzer_state = BUZZER_OFF;

// set up the initial environment of each state (if state transitions occur)
void fsmVerPedRun()
{
	switch (ver_ped)
	{
		case PED_OFF:
			if (isButtonPressed(BUTTON_PED_VER) && mode == AUTO_MODE)
			{
				ver_ped = PED_ON;
			}
			break;
		case PED_ON:
			switch (vertical_state)
			{
				case AUTO_GREEN:
				case AUTO_YELLOW:
					setTimer(3, BUZZER_time_stop);
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, BUZZER_pul_stop);
					ver_buzzer_state = BUZZER_ON;
					ver_ped = WALK_STOP;
					break;
				case AUTO_RED:
					setTimer(3, BUZZER_time_allow);
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, BUZZER_pul_allow);
					ver_buzzer_state = BUZZER_ON;
					ver_ped = WALK_ALLOW;
					break;
				default:
					break;
			}
			if (mode != AUTO_MODE)
			{
				ver_ped = PED_OFF;
			}
			break;
		case WALK_STOP:
			if (vertical_state == AUTO_RED)
			{
				setTimer(3, BUZZER_time_allow);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, BUZZER_pul_allow);
				ver_buzzer_state = BUZZER_ON;
				ver_ped = WALK_ALLOW;
			}
			if (mode != AUTO_MODE)
			{
				ver_ped = PED_OFF;
			}
			break;
		case WALK_ALLOW:
			if (currentCounter(1) <= TIME_LEFT_FOR_LOUDER && mode == AUTO_MODE)
			{
				setTimer(5, PED_LED_TOGGLE_DURATION);
				ver_buzzer_time = BUZZER_time_allow - 200;
				setTimer(3, ver_buzzer_time);
				ver_pul = BUZZER_pul_allow + 100;
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, ver_pul);
				ver_buzzer_state = BUZZER_ON;
				ver_ped = BUZZER_LOUDER;
			}
			if (mode != AUTO_MODE)
			{
				ver_ped = PED_OFF;
			}
			break;
		case BUZZER_LOUDER:
			if (vertical_state == AUTO_GREEN || mode != AUTO_MODE)
			{
				ver_ped = PED_OFF;
			}
			break;
		default:
			break;
	}
}

// set up the initial environment of each state (if state transitions occur)
void fsmHorPedRun()
{
	switch (hor_ped)
	{
		case PED_OFF:
			if (isButtonPressed(BUTTON_PED_HOR) && mode == AUTO_MODE)
			{
				hor_ped = PED_ON;
			}
			break;
		case PED_ON:
			switch (horizontal_state)
			{
				case AUTO_GREEN:
				case AUTO_YELLOW:
					setTimer(2, BUZZER_time_stop);
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, BUZZER_pul_stop);
					hor_buzzer_state = BUZZER_ON;
					hor_ped = WALK_STOP;
					break;
				case AUTO_RED:
					setTimer(2, BUZZER_time_allow);
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, BUZZER_pul_allow);
					hor_buzzer_state = BUZZER_ON;
					hor_ped = WALK_ALLOW;
					break;
				default:
					break;
			}
			if (mode != AUTO_MODE)
			{
				hor_ped = PED_OFF;
			}
			break;
		case WALK_STOP:
			if (horizontal_state == AUTO_RED)
			{
				setTimer(2, BUZZER_time_allow);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, BUZZER_pul_allow);
				hor_buzzer_state = BUZZER_ON;
				hor_ped = WALK_ALLOW;
			}
			if (mode != AUTO_MODE)
			{
				hor_ped = PED_OFF;
			}
			break;
		case WALK_ALLOW:
			if (currentCounter(0) <= TIME_LEFT_FOR_LOUDER && (mode == AUTO_MODE))
			{
				setTimer(4, PED_LED_TOGGLE_DURATION);
				hor_buzzer_time = BUZZER_time_allow - 200;
				setTimer(2, hor_buzzer_time);
				hor_pul = BUZZER_pul_allow + 100;
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, hor_pul);
				hor_buzzer_state = BUZZER_ON;
				hor_ped = BUZZER_LOUDER;
			}
			if (mode != AUTO_MODE)
			{
				hor_ped = PED_OFF;
			}
			break;
		case BUZZER_LOUDER:
			if (mode != AUTO_MODE || horizontal_state == AUTO_GREEN)
			{
				hor_ped = PED_OFF;
			}
			break;
		default:
			break;
	}
}

// configure the running environment of states
void fsmPedestrianModeRun()
{
	fsmVerPedRun();
	fsmHorPedRun();

	switch (ver_ped)
	{
		case PED_OFF:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_OFF);
			//The vertical buzzer is off
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
			break;
		case PED_ON:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_OFF);
			//The vertical buzzer is off
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
			break;
		case WALK_STOP:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_OFF);
			if (isTimerUp(3))
			{
				setTimer(3, BUZZER_time_stop);
				switch (ver_buzzer_state)
				{
					case BUZZER_ON:
						ver_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
						break;
					case BUZZER_OFF:
						ver_buzzer_state = BUZZER_ON;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, BUZZER_pul_stop);
						break;
					default:
						break;
				}
			}
			break;
		case WALK_ALLOW:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_ON);
			if (isTimerUp(3))
			{
				setTimer(3, BUZZER_time_allow);
				switch (ver_buzzer_state)
				{
					case BUZZER_ON:
						ver_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
						break;
					case BUZZER_OFF:
						ver_buzzer_state = BUZZER_ON;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, BUZZER_pul_allow);
						break;
					default:
						break;
				}
			}
			break;
		case BUZZER_LOUDER:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			if (isTimerUp(5))
			{
				setTimer(5, PED_LED_TOGGLE_DURATION);
				HAL_GPIO_TogglePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin);
			}

			if (isTimerUp(3))
			{
				switch (ver_buzzer_state)
				{
					case BUZZER_ON:
						ver_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
						break;
					case BUZZER_OFF:
						// Buzzer is louder and faster after each cycle
						ver_buzzer_state = BUZZER_ON;
						if (ver_buzzer_time - 200 >= 200)
						{
							ver_buzzer_time -= 200;
						}
						if (ver_pul + 100 <= 950)
						{
							ver_pul += 100;
						}
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, ver_pul);
						break;
					default:
						break;
				}
				setTimer(3, ver_buzzer_time);
			}
			break;
		default:
			break;
	}

	switch (hor_ped)
	{
		case PED_OFF:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_OFF);
			//The horizontal buzzer is off
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
			break;
		case PED_ON:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_OFF);
			//The horizontal buzzer is off
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
			break;
		case WALK_STOP:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_OFF);
			if (isTimerUp(2))
			{
				setTimer(2, BUZZER_time_stop);
				switch (hor_buzzer_state)
				{
					case BUZZER_ON:
						hor_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
						break;
					case BUZZER_OFF:
						hor_buzzer_state = BUZZER_ON;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, BUZZER_pul_stop);
						break;
					default:
						break;
				}
			}
			break;
		case WALK_ALLOW:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_ON);
			if (isTimerUp(2))
			{
				setTimer(2, BUZZER_time_allow);
				switch (hor_buzzer_state)
				{
					case BUZZER_ON:
						hor_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
						break;
					case BUZZER_OFF:
						hor_buzzer_state = BUZZER_ON;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, BUZZER_pul_allow);
						break;
					default:
						break;
				}
			}
			break;
		case BUZZER_LOUDER:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			if (isTimerUp(4))
			{
				setTimer(4, PED_LED_TOGGLE_DURATION);
				HAL_GPIO_TogglePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin);
			}

			if (isTimerUp(2))
			{
				switch (hor_buzzer_state)
				{
					case BUZZER_ON:
						hor_buzzer_state = BUZZER_OFF;
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
						break;
					case BUZZER_OFF:
						// Buzzer is louder and faster after each cycle
						hor_buzzer_state = BUZZER_ON;
						if (hor_buzzer_time - 200 >= 200)
						{
							hor_buzzer_time -= 200;
						}
						if (hor_pul + 100 <= 950)
						{
							hor_pul += 100;
						}
						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, hor_pul);
						break;
					default:
						break;
				}
				setTimer(2, hor_buzzer_time);
			}
			break;
		default:
			break;
	}
}
