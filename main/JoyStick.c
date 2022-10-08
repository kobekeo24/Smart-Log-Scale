/*
 * JoyStick.c
 *
 *  Created on: Oct 7, 2022
 *      Author: 13372
 */

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_Adc_cal.h"
#include "JoyStick.h"
#include "tasks_common.h"

#define JOYSTICK_Y_ADC			ADC1_CHANNEL_6
#define JOYSTICK_X_ADC			ADC1_CHANNEL_7


uint16_t getXcoordinate(void)
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(JOYSTICK_X_ADC,ADC_ATTEN_DB_0);
	return adc1_get_raw(JOYSTICK_X_ADC);
}

uint16_t getYcoordinate(void)
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(JOYSTICK_Y_ADC,ADC_ATTEN_DB_0);
	return adc1_get_raw(JOYSTICK_Y_ADC);
}

/**
 * Joy Stick Task
 */
static void JoyStick_task(void *pvParamenter)
{
	printf("Starting joy stick task\n\n");
	//Initialize ADC

	for(;;)
	{
		printf("===== Reading Joy Stick coordinates =====\n");

		int val_x = getXcoordinate();
		int val_y = getYcoordinate();

		printf("X coordinate %d\n",val_x);
		printf("Y coordinate %d\n",val_y);

		//Delay 2 seconds before sampling
		vTaskDelay(2000/portTICK_RATE_MS);

	}
}

/**
 * Starts JOYSTICK Task
 */
void JoyStick_task_start(void)
{
	xTaskCreatePinnedToCore(&JoyStick_task,"JoyStick_task",JOYSTICK_STACK_SIZE,NULL,JOYSTICK_PRIORITY,NULL,JOYSTICK_CORE_ID);

}
