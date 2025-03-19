/*
 * fsm_auto.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#include "fsm_auto.h"
extern int TIME_FOR_GREEN;
extern int TIME_FOR_RED;
extern int TIME_FOR_AMBER;
extern int time_green;
extern int time_red;
extern int time_amber;
void fsm_auto_run(){
	switch(status){
	case INIT:
		init();
		if(1){

			setTimer(0, (time_green+1)*1000);
		    setTimer(9, 100); // for scan led
		    setTimer(1, 1000); // for display 7 seg
		    setTimer(8, 1000); // signal timer
		    status = AUTO_GREEN_RED;
		   // snprintf(buffer, sizeof(buffer), "     MANUAL       ");

		}
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_RED;
			clear_all_led();
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			clear_all_led();
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		break;
	case AUTO_GREEN_RED:
		auto_green_red();
		if(timers[0].flag == 1) // flag for transition
		{
			time_green = TIME_FOR_GREEN;
			time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1 ;
			time_red = TIME_FOR_RED - TIME_FOR_GREEN - 1;
			setTimer(0, (time_amber+1)*1000);
			status = AUTO_AMBER_RED;
		}
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_RED;
			clear_all_led();
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			clear_all_led();
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		break;
	case AUTO_AMBER_RED:
		auto_amber_red();
		if(timers[0].flag == 1){
			time_red = TIME_FOR_RED;
			time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1;
			time_green = TIME_FOR_GREEN;
			setTimer(0, (time_green+1)*1000);
			status = AUTO_RED_GREEN;
		}
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_RED;
			clear_all_led();
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			clear_all_led();
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		break;
	case AUTO_RED_GREEN:
		auto_red_green();
		if(timers[0].flag == 1){
			time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1;
			time_red = TIME_FOR_RED-TIME_FOR_GREEN - 1;
			time_green = TIME_FOR_GREEN;
			setTimer(0, (time_amber+1)*1000);
			status = AUTO_RED_AMBER;
		}
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_RED;
			clear_all_led();
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			clear_all_led();
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		break;
	case AUTO_RED_AMBER:
		auto_red_amber();
		if(timers[0].flag == 1){
			time_green = TIME_FOR_GREEN;
			time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1;
			time_red = TIME_FOR_RED;
			setTimer(0, (time_green+1)*1000);
			status = AUTO_GREEN_RED;
		}
		if(isButtonPressed(0) || isButtonLongPressed(0)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			status = MODIFY_RED;
			clear_all_led();
			setTimer(3, 500); // timer for bliking led 2hz on mode modify
		}
		if(isButtonPressed(1) || isButtonLongPressed(1)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
			clear_all_led();
			status = MANUAL_GREEN_RED;
		}
		if(isButtonPressed(2) || isButtonLongPressed(2)){
			HAL_GPIO_TogglePin(SIGNAL_BUTTON_GPIO_Port, SIGNAL_BUTTON_Pin);
		}
		break;
	default:
		break;
	}
}

