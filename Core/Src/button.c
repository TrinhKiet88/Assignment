/*
 * button.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#include "button.h"

typedef struct {
	GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
    int KeyReg0;
    int KeyReg1;
    int KeyReg2;
    int KeyReg3;
    int TimeOutForKeyPress;
    int flag;
    int long_pressed;
    int pressed;
} Button;

Button buttons[NUM_BUTTONS];

Button buttons[NUM_BUTTONS] = {
    {BUTTON0_GPIO_Port, BUTTON0_Pin, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, 0},
    {BUTTON1_GPIO_Port, BUTTON1_Pin, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, 0},
    {BUTTON2_GPIO_Port, BUTTON2_Pin, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, 0}
};

int isButtonPressed(int index){
	if(buttons[index].flag == 1){
		buttons[index].flag = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(buttons[index].long_pressed == 1){
		buttons[index].long_pressed = 0;
		return 1;
	}
	return 0;
}
void getKeyInput() {
    for (int index = 0; index < NUM_BUTTONS; index++) {
        buttons[index].KeyReg2 = buttons[index].KeyReg1;
        buttons[index].KeyReg1 = buttons[index].KeyReg0;
        // Read the current state of the button
        buttons[index].KeyReg0 = HAL_GPIO_ReadPin(buttons[index].GPIO_Port, buttons[index].GPIO_Pin);

        // Check for stable button state
        if ((buttons[index].KeyReg1 == buttons[index].KeyReg0) && (buttons[index].KeyReg1 == buttons[index].KeyReg2)) {
            if (buttons[index].KeyReg2 != buttons[index].KeyReg3) {
                buttons[index].KeyReg3 = buttons[index].KeyReg2;

                // Check if button is in pressed state
                if (buttons[index].KeyReg3 == PRESSED_STATE) {
                    buttons[index].TimeOutForKeyPress = 500;
                    buttons[index].flag = 1;
                }

            } else {
                // Decrease timeout if button is held down
                buttons[index].TimeOutForKeyPress--;
                if (buttons[index].TimeOutForKeyPress == 0) {
                    buttons[index].TimeOutForKeyPress = 500;
                    if (buttons[index].KeyReg3 == PRESSED_STATE) {
                        buttons[index].long_pressed = 1;
                    }
                }
            }
        }
    }
}

