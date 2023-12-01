/*
 * f.timer.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */


#include "f_timer.h"

int timer_counter[NUM_OF_TIMER];
int timer_flag[NUM_OF_TIMER];

int currentCounter(int timer)
{
	return timer_counter[timer];
}

int isTimerUp(int timer)
{
	return (timer_flag[timer] == 1);
}

void setTimer(int timer, int duration)
{
	timer_counter[timer] = duration / timer_cycle;
	timer_flag[timer] = 0;
}

void timerRun()
{
	for (int timer = 0; timer < NUM_OF_TIMER; timer++)
	{
		if (timer_counter[timer] > 0)
		{
			timer_counter[timer] --;
			if (timer_counter[timer] == 0)
			{
				timer_flag[timer] = 1;
			}
		}
	}
}
