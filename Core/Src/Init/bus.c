/*
 * bus.c
 *
 *  Created on: Feb 6, 2025
 *      Author: daoch
 */


#include <bus.h>
#include "registers_tools.h"
#include "registers_defs.h"

void busInit(void) {
	busRegisterSetup();
}
void busRegisterSetup(void) {
	// Enable clock in AHB1
	registerBitSet(REG_RCC_AHB1ENR, (BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_7)); 	// For using general purpose I/O function PORT A, B, C, D, H

	// Enable clock in APB1
	registerBitSet(REG_RCC_APB1ENR, (BIT_4 | BIT_5)); 					// For using basic timer 6, 7
	registerBitSet(REG_RCC_APB1ENR, BIT_21); 							// For using I2C1

	// Enable clock in APB2
	registerBitSet(REG_RCC_APB2ENR, BIT_14); 							// For using system configuration function in PORT A
	registerBitSet(REG_RCC_APB2ENR, (BIT_0 | BIT_1)); 					// For using advanced timer 1 and timer 8
	registerBitSet(REG_RCC_APB2ENR, BIT_12);							// For using PSI1


}
