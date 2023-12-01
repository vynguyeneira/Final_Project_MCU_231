/*
 * f_uart.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */


#include "f_uart.h"

void uartTransmit7SEG(int timer_counter) {
	char str[50];
	uint8_t counter = (timer_counter / 1000) % 100;
	sprintf(str, "!7SEG:%02d#", counter);
	uint8_t str_len = (uint8_t)strlen(str);
	for (uint8_t i = 0; i < str_len; ++i) {
		HAL_UART_Transmit(&huart2, (uint8_t*)(str + i), 1, 50);
	}
}

void fsmUARTRun() {
	// Only transmit horizontal counter value
	if (isTimerUp(6)) {
		// The receiving application only accept message of the form "!7SEG:xx#
		uartTransmit7SEG(currentCounter(0));
		setTimer(6, UART_TIME_STEP);
	}
}
