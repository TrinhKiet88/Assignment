/*
 * fsm_manual.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MANUAL_GREEN_RED:
		manual_green_red();
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MANUAL_RED_GREEN;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = INIT;
		}

		break;
	case MANUAL_RED_GREEN:
		manual_red_green();
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = INIT;
		}
//	    //lcd_clear_display();
//	    	lcd_goto_XY(1, 0);
//	    	lcd_send_string("    MANUAL       ");
		break;
	default:
		break;

	}
}

