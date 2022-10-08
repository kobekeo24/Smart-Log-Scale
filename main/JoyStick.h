/*
 * JoyStick.h
 *
 *  Created on: Oct 7, 2022
 *      Author: 13372
 */

#include "driver/gpio.h"
#include "driver/adc.h"

#ifndef MAIN_JOYSTICK_H_
#define MAIN_JOYSTICK_H_

#define JOYSTICK_Y_GPIO			34

#define JOYSTICK_X_GPIO			35

uint16_t getXcoordinate(void);

uint16_t getYcoordinate(void);

/**
 * Starts JOYSTICK Task
 */
void JoyStick_task_start(void);

#endif /* MAIN_JOYSTICK_H_ */
