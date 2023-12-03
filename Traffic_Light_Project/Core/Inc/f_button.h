/*
 * f_button.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Vy Nguyen
 */

#ifndef INC_F_BUTTON_H_
#define INC_F_BUTTON_H_

#include "f_global.h"
#include "main.h"

int isButtonPressed (int button);
int isButtonLongPressed (int button);
void buttonProcessing();
void fsmButtonReset(int button);
void fsmButtonRun(int button);

#endif /* INC_F_BUTTON_H_ */
