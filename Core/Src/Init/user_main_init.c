/*
 * main_init.c
 *
 *  Created on: Dec 10, 2024
 *      Author: daoch
 */

#include <i2c.h>
#include "user_main_init.h"
#include "bus_init.h"
#include "gpios_init.h"
#include "interrupts_init.h"


void userInit(void) {
	busInit();
	gpiosInit();
	interruptsInit();
	i2cInit();
}

