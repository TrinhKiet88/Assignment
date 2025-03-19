/*
 * fsm_modify.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#include "fsm_modify.h"

extern int newTime;
extern int TIME_FOR_GREEN;
extern int TIME_FOR_RED;
extern int TIME_FOR_AMBER;
extern int time_green;
extern int time_red;
extern int time_amber;
void fsm_modify_run(){
	switch(status){
	case MODIFY_RED:
		modify_red_led();
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_GREEN;
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
			newTime = 0;
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			newTime++;
			if(newTime > 99){
				newTime = 0;
			}
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			TIME_FOR_RED = newTime;
			newTime = 0;
			status = MODIFY_GREEN;
		}
		break;
	case MODIFY_GREEN:
		modify_green_led();
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = INIT;
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
			newTime = 0;
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			newTime++;
			if(newTime > 99){
				newTime = 0;
			}
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			TIME_FOR_GREEN = newTime;
			newTime = 0;
			status = INIT;
		}
		break;
//	case MODIFY_AMBER:
//		modify_amber_led();
//		if(isButtonPressed(0) || isButtonLongPressed(0)){
//			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
//			status = INIT;
//			newTime = 0;
//		}
//		if(isButtonPressed(1) || isButtonLongPressed(1)){
//			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
//			newTime++;
//			if(newTime > 99){
//				newTime = 0;
//			}
//		}
//		if(isButtonPressed(2) || isButtonLongPressed(2)){
//			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
//			TIME_FOR_AMBER = newTime;
//			newTime = 0;
//			status = INIT;
//		}
//		break;
	default:
		break;
	}
}

