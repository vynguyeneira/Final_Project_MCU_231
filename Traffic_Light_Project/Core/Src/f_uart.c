/*
 * f_uart.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */


#include "f_uart.h"

int save_time_count = -1;

void uartTransmit7SEG(uint8_t counter) {
	char str[50];
	sprintf(str, "!7SEG:%02d#", counter);
	uint8_t str_len = (uint8_t)strlen(str);
	for (uint8_t i = 0; i < str_len; ++i) {
		HAL_UART_Transmit(&huart2, (uint8_t*)(str + i), 1, 50);
	}
}

void uartProcessing() {
	// The receiving application only accept message of the form "!7SEG:xx#
	switch (mode)
	{
		case AUTO_MODE:
			// Only transmit horizontal counter value
			if (isTimerUp(6))
			{
				uint8_t formatted_counter = (currentCounter(0) / 1000) % 100;
				uartTransmit7SEG(formatted_counter);
				setTimer(6, UART_TIME_STEP);
			}
			break;
		case INC_RED:
		case INC_GREEN:
		case INC_YELLOW:
			// Print TUNING value only there's a change
			if (time_count != save_time_count)
			{
				uartTransmit7SEG(time_count);
				save_time_count = time_count;
			}
			break;
		default:
			// Reset for future printing of TUNING value
			save_time_count = -1;
			break;
	}
}
