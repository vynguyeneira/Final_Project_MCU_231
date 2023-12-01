/*
 * f.global.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#ifndef INC_F_GLOBAL_H_
#define INC_F_GLOBAL_H_

#include "main.h"

/*
 * Define global Variables
 */

extern int timer_cycle;
extern int timer_for_key_pressed;
extern int mode;

extern int RED_time;
extern int YELLOW_time;
extern int GREEN_time;

/*
 * Define for AUTO MODE
 */

#define INIT			0
#define AUTO_MODE		1
#define AUTO_RED		2
#define AUTO_YELLOW		3
#define AUTO_GREEN		4

/*
 * Define for MANUAL MODE
 */
#define MANU_MODE		5
#define MANU_RED		6
#define MANU_YELLOW		7
#define MANU_GREEN		8

/*
 * Define for TUNING MODE
 */
#define	INC_RED			9
#define INC_YELLOW		10
#define	INC_GREEN		11

/*
 * Define for PEDESTRIAN MODE
 */
#define PED_OFF					12
#define PED_ON					13
#define WALK_ALLOW				14
#define BUZZER_LOUDER			15
#define WALK_STOP				16
#define PED_LED_TOGGLE_DURATION	500

/*
 * Define for LEDs
 */
#define LED_ON		GPIO_PIN_RESET
#define LED_OFF		GPIO_PIN_SET

/*
 * Define for Buzzer
 */
#define BUZZER_time_allow		1000
#define BUZZER_time_stop		500
#define BUZZER_pul_allow		450
#define BUZZER_pul_stop			950
#define BUZZER_OFF				0
#define BUZZER_ON				1
#define TIME_LEFT_FOR_LOUDER	5000

/*
 * Define for Timer
 * Timer0 for horizontal LEDs, Timer1 for vertical LEDs,
 * Timer2 for horizontal buzzer, Timer3 for vertical buzzer
 * Timer4 for pedestrian horizontal LED toggling
 * Timer5 for pedestrian horizontal LED toggling
 * Timer6 for UART transmitting
 * Timer7 for buttons reading
 */
#define NUM_OF_TIMER	8

/*
 * Define for Button
 */
#define NUM_OF_BUTTONS		5

#define BUTTON_MODE			0
#define BUTTON_SET			1
#define BUTTON_INC			2
#define BUTTON_PED_VER		3
#define BUTTON_PED_HOR		4
#define BUTTON_TIME_STEP	10

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

/*
 * Define for UART
 */
#define UART_TIME_STEP 1000

#endif /* INC_F_GLOBAL_H_ */
