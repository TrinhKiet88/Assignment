/*
 * led_output.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */
#include "led_output.h"
#include "lcd_i2c.h"
#include "stdio.h"
int TIME_FOR_GREEN = 3;
int TIME_FOR_RED = 5;
int TIME_FOR_AMBER = 2;
int time_red;
int time_green;
int time_amber;
int newTime = 0;

void init(){
	// HAL_GPIO_TogglePin(GPIOA, SIGNAL_Pin);
	if(TIME_FOR_GREEN < TIME_FOR_RED){
		 time_red = TIME_FOR_RED;
		 time_green = TIME_FOR_GREEN;
		 time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1;
	}
	else {
	 time_red = 5;
	 time_green = 3;
	 time_amber = 2;
	}
}
void auto_green_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);


	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);



//	update_led_buffer_A(time_green);
//	update_led_buffer_B(time_red);
	display_lcd(time_green, time_red);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_green--;
			time_red--;
			setTimer(1, 1000);
		}
}
void auto_amber_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);


	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


//	update_led_buffer_A(time_amber);
//	update_led_buffer_B(time_red);
	display_lcd(time_amber, time_red);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_amber--;
			time_red--;
			setTimer(1, 1000);
		}
}
void auto_red_green(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


//	update_led_buffer_A(time_red);
//	update_led_buffer_B(time_green);
	display_lcd(time_red, time_green);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_red--;
			time_green--;
			setTimer(1, 1000);
		}
}
void auto_red_amber(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);


	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);


//	update_led_buffer_A(time_red);
//	update_led_buffer_B(time_amber);
	display_lcd(time_red, time_amber);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_red--;
			time_amber--;
			setTimer(1, 1000);
		}
}

// use timer 3
char buf[16] = {0};
void modify_red_led(){

	if(timers[3].flag == 1){

		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);

		setTimer(3, 500);
	}
//	update_led_buffer_B(2); // mode name
//	update_led_buffer_A(newTime); //new time
	lcd_goto_XY(1, 0);
	   lcd_send_string("    MODIFY        ");
	snprintf(buf, sizeof(buf), "red:%02d",newTime);
	lcd_goto_XY(0, 0);
	lcd_send_string(buf);
}
void modify_green_led(){
	if(timers[3].flag == 1){

		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);

		setTimer(3, 500);
	}
//	update_led_buffer_B(3); // mode name
//	update_led_buffer_A(newTime); // new time
	lcd_goto_XY(1, 0);
	   lcd_send_string("    MODIFY        ");
	snprintf(buf, sizeof(buf), "green:%02d",newTime);
	lcd_goto_XY(0, 0);
	lcd_send_string(buf);
}
void modify_amber_led(){
	if(timers[3].flag == 1){
		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);

		setTimer(3, 500);
	}
//	update_led_buffer_B(4); //  mode name
//	update_led_buffer_A(newTime); //new time
//	display();
	lcd_goto_XY(1, 0);
	   lcd_send_string("    MODIFY        ");
	snprintf(buf, sizeof(buf), "amber:%02d",newTime);
	lcd_goto_XY(0, 0);
	lcd_send_string(buf);
}
void clear_all_led(){
	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);


}
void manual_green_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);


	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);



//	update_led_buffer_B(1); //  mode name
//	update_led_buffer_A(0); //00
//	display();
    	lcd_goto_XY(1, 0);
    	lcd_send_string("    MANUAL1       ");
}
void manual_red_green(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);


	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


	//update_led_buffer_B(1); //  mode name
	//update_led_buffer_A(0); //00
//	display();
    	lcd_goto_XY(1, 0);
    	lcd_send_string("    MANUAL2       ");}


