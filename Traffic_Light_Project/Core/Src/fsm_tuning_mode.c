/*
 * fsm_tuning_mode.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#include "fsm_tuning_mode.h"

int time_count = 0;

void fsmTuningModeRun()
{
	switch (mode)
	{
		case INC_RED:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE))
			{
				mode = AUTO_MODE;
				resetLight();
			}

			// Set the time duration of the red LEDs
			//when press SET button
			if(isButtonPressed(BUTTON_SET))
			{
				RED_time = time_count * 1000;
			}

			// Increase the time duration of the red LEDs
			// when INC button is pressed or auto increased the red
			// LEDs every 500ms if button is pressed longer than 1 second
			fsmButtonRun(BUTTON_INC);
			break;

		case INC_GREEN:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE))
			{
				mode = AUTO_MODE;
				resetLight();
			}

			// Set the time duration of the green LEDs
			//when press SET button
			if(isButtonPressed(BUTTON_SET))
			{
				GREEN_time = time_count * 1000;
			}

			// Increase the time duration of the green LEDs
			// when INC button is pressed or auto increased the green
			// LEDs every 500ms if button is pressed longer than 1 second
			fsmButtonRun(BUTTON_INC);
			break;

		case INC_YELLOW:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE))
			{
				mode = AUTO_MODE;
				resetLight();
			}

			// Set the time duration of the yellow LEDs
			//when press SET button
			if(isButtonPressed(BUTTON_SET))
			{
				YELLOW_time = time_count * 1000;
			}

			// Increase the time duration of the red LEDs
			// when INC button is pressed or auto increased the red
			// LEDs every 500ms if button is pressed longer than 1 second
			fsmButtonRun(BUTTON_INC);
			break;

		default:
			break;
	}
}
