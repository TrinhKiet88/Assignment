/*
 * software_timer.c
 *
 *  Created on: Dec 27, 2024
 *      Author: USER
 */

#include "software_timer.h"


#define NUM_TIMERS 10// Define the number of timers
Timer timers[NUM_TIMERS];
int timer_cycle = 100;

void setTimer(int index, int duration) {
    if (index >= 0 && index < NUM_TIMERS) {
        timers[index].counter = duration / timer_cycle;
        timers[index].flag = 0;
    }
}

void timerRun() {
    for (int i = 0; i < NUM_TIMERS; i++) {
        if (timers[i].counter > 0) {
            timers[i].counter--;
            if (timers[i].counter <= 0) {
                timers[i].flag = 1;
            }
        }
    }
}

