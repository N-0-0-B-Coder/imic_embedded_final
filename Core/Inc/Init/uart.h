/*
 * uart.h
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#ifndef INC_INIT_UART_H_
#define INC_INIT_UART_H_

#include "stm32f4xx_hal.h"

void print_uart(const char *format, ...);

#define PRINT_UART(f_, ...) print_uart(f_, ##__VA_ARGS__)


void MX_UART4_Init(void);


#endif /* INC_INIT_UART_H_ */
