/*
 * uart.c
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "uart.h"

UART_HandleTypeDef huart4;

void print_uart(const char *format, ...) {
    char _buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(_buffer, sizeof(_buffer), format, args);
    va_end(args);

    HAL_UART_Transmit(&huart4, (uint8_t *)_buffer, strlen(_buffer), 1000);
    osDelay(10);
}

void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    while(1){}
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}
