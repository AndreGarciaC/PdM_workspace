/*
 * API_delay.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Andrea Garcia & Gonzalo Vila
 */

#include "API_uart.h"

UART_HandleTypeDef UartHandle;

static void uartPrintConfig(void)
{
		printf("Velocidad serial: %lu baudios.\n\r",UartHandle.Init.BaudRate);
		printf("Max longitud de caracteres: %lu .\n\r",UartHandle.Init.WordLength);
		printf("Bits de parada: %lu .\n\r",UartHandle.Init.StopBits);
		printf("Bit de paridad: %lu .\n\r",UartHandle.Init.Parity);
}

bool uartInit()
{
	UartHandle.Instance        = USARTx;
	UartHandle.Init.BaudRate   = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits   = UART_STOPBITS_1;
	UartHandle.Init.Parity     = UART_PARITY_ODD;
	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode       = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		return false;
	}
	uartPrintConfig();
	return true;
}

void uartSendString(uint8_t *pstring)
{
	uint8_t i, count = 0;
	for(i=0; *(pstring + i) !=0; i++)
	{
		count++;
	}
	HAL_UART_Transmit(&UartHandle, pstring, count, 0xFFFF);
}

