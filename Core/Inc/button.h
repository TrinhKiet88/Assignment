/*
 * button.h
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"
#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define NUM_BUTTONS 3

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
