/*
 * main_init.c
 *
 *  Created on: Dec 10, 2024
 *      Author: daoch
 */

#include <bus.h>
#include <gpios.h>
#include <i2c.h>
#include <interrupts.h>
#include <uart.h>
#include <timers.h>
#include "user_main_init.h"

void userInit(void) {
	busInit();
	gpiosInit();
	interruptsInit();
	i2cInit();
	timersInit();
	MX_UART4_Init();
}

