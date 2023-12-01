/*
 * f.button.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */


#include "f_button.h"

int button_flag[NUM_OF_BUTTONS];
int button_long_flag[NUM_OF_BUTTONS];
GPIO_PinState key_reg[NUM_OF_BUTTONS][4];
int counter_for_key_pressed[NUM_OF_BUTTONS];

int isButtonPressed(int button)
{
	if (button_flag[button])
	{
		button_flag[button] = 0;
		return 1;
	}

	else return 0;
}

int isButtonLongPressed(int button)
{
	if (button_long_flag[button])
	{
		button_long_flag[button] = 0;
		return 1;
	}

	else return 0;
}

void subKeyProcess(int button)
{
	button_flag[button] = 1;
}

void subKeyLongProcess(int button)
{
	button_long_flag[button] = 1;
}

void resetKey(int button)
{
	button_flag[button] = 0;
	button_long_flag[button] = 0;
}

void setKeyTimer(int button)
{
	counter_for_key_pressed[button] = timer_for_key_pressed / timer_cycle;
}

void getKeyInput()
{
	for (int button = 0; button < NUM_OF_BUTTONS; button++)
	{

	}
}

























