/*
 * UartControl.c
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#include <stdio.h>
#include <stdbool.h>
#include <cmsis_os2.h>
#include "uart_control.h"

void CreateUARTLedControlThread(void) {
  // uartLedControl Thread
  osThreadId_t uartLedControl;
  const osThreadAttr_t uartLedControl_attributes ={
	.name = "uartLedControl",
	.stack_size = 512 * 4,
	.priority = (osPriority_t) osPriorityNormal,
  };

  uartLedControl = osThreadNew(startUARTLedControl, NULL, &uartLedControl_attributes);
  if (NULL == uartLedControl) PRINT_UART("uartLedControl Thread is failed to be created\r\n");
  else PRINT_UART("uartLedControl Thread created successfully\r\n");
}
void startUARTLedControl(void *argument) {
	PRINT_UART("uartLedControl Thread run \r\n");
	osDelay(1);
	for (;;) {
		osDelay(1);
	}
}