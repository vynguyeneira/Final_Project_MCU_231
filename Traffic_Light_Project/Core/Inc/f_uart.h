/*
 * f_uart.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#ifndef INC_F_UART_H_
#define INC_F_UART_H_

#include "f_global.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

void uartTransmit7SEG(int);
void fsmUARTRun();

#endif /* INC_F_UART_H_ */
