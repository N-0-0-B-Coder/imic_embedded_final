/*
 * button.c
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#include <stdio.h>
#include <stdbool.h>
#include <cmsis_os2.h>
#include "button.h"
#include "led_tools.h"

static bool timer6Alarm = false;
static bool timer6LedToggle = false;
static bool timer7Alarm = false;
static bool timer7LedToggle = false;
static bool extiAlarmPA0 = false;
static bool extiButtonToggle = false;

void CreateButtonThread(void) {
    // buttonHandle Thread
    osThreadId_t buttonHandle;
    const osThreadAttr_t buttonHandle_attributes = {
        .name = "buttonInterference",
        .stack_size = 768 * 4,
        .priority = (osPriority_t) osPriorityNormal3,
    };

    buttonHandle = osThreadNew(ButtonHandleTask, NULL, &buttonHandle_attributes);
    if (NULL == buttonHandle) PRINT_UART("buttonHandle Thread is failed to be created\r\n");
    else PRINT_UART("buttonHandle Thread created successfully\r\n");


    // buttonExecute Thread
    osThreadId_t buttonExecute;
    const osThreadAttr_t buttonExecute_attributes = {
        .name = "buttonExecution",
        .stack_size = 512 * 4,
        .priority = (osPriority_t) osPriorityNormal2,
    };

    buttonExecute = osThreadNew(ButtonExecuteTask, NULL, &buttonExecute_attributes);
    if (NULL == buttonExecute) PRINT_UART("buttonExecute Thread is failed to be created\r\n");
    else PRINT_UART("buttonExecute Thread created successfully\r\n");
}

void ButtonHandleTask(void *argument) {
	PRINT_UART("Button Handler Thread run\r\n");
	osDelay(1);
	for(;;) {
		if(extiAlarmPA0) {
			interferenceCheck();
		}


		osDelay(1);
	}
}
void ButtonExecuteTask(void *argument) {
	PRINT_UART("Button Execute Thread run\r\n");
	osDelay(1);
	for(;;) {
		if (extiButtonToggle) {

			if (timer6Alarm) {
				timer6Alarm = false;
				timer6LedToggle ^= 1;
				ledSet(LED_GREEN, timer6LedToggle);
			}

			if (timer7Alarm) {
				timer7Alarm = false;
				timer7LedToggle ^= 1;
				ledSet(LED_BLUE, timer7LedToggle);
			}
		}
		else {
			ledSet(LED_GREEN, 0);
			ledSet(LED_BLUE, 0);
		}
		osDelay(1);
	}
}


