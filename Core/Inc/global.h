/*
 * global.h
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include  "software_timer.h"
#include "button.h"
#include "main.h"
//#include "7seg_led.h"
#include "fsm_auto.h"
#include "fsm_modify.h"
#include "led_output.h"
#include "stm32f1xx_hal.h"
#include "lcd_i2c.h"
#include "fsm_manual.h"

extern int status;

#define INIT 1
#define AUTO_GREEN_RED 2
#define AUTO_AMBER_RED 3
#define AUTO_RED_GREEN 4
#define AUTO_RED_AMBER 5


#define MODIFY_RED 22
#define MODIFY_GREEN 23
#define MODIFY_AMBER 24

#define MANUAL_GREEN_RED 32
#define MANUAL_RED_GREEN 33

#endif /* INC_GLOBAL_H_ */
