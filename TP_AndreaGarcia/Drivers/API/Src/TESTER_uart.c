/*
 * API_uart.c
 *
 *  Created on: 03 dec. 2021
 *      Author: Andrea García
 */

#include <TESTER_uart.h>

static void uartPrintConfig(void);
static void Error_Handler(void);

void Uart_Init(void)
{
	UartHandle.Instance = USARTx;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		Error_Handler();
	}
	else
	{
		uartPrintConfig();
	}
}

void uartSendMsg(uint8_t *pstring)
{
	uint8_t i, count = 0;
	for(i=0; *(pstring + i) !=0; i++)
	{
		count++;
	}
	HAL_UART_Transmit(&UartHandle, pstring, count, 0xFFFF);
}

bool uartReadMsgPR310()
{
	char value[0xFF];
	if(__HAL_UART_GET_FLAG(&UartHandle, UART_FLAG_RXNE)>=1)
	{
		HAL_UART_Receive(&UartHandle, (uint8_t *)value, strlen(value),0xFF);
		uartSendMsg((uint8_t *)value);
		uartSendMsg((uint8_t *)("\rIngrese 1 o 0\n\r"));
		if(strcmp (value, "1")==0)
		{
			uartSendMsg((uint8_t *)("\r Exito \n\r"));
			__HAL_UART_CLEAR_FLAG(&UartHandle, UART_FLAG_RXNE);
			return true;
		}
		else if(strcmp (value, "0")==0)
		{
			uartSendMsg((uint8_t *)("\r Fallo \n\r"));
			__HAL_UART_CLEAR_FLAG(&UartHandle, UART_FLAG_RXNE);
			return false;
		}
	}
	return false;
}

static void uartPrintConfig(void)
{
	uartSendMsg((uint8_t *)"UART inicializado\n\r");
	printf("Velocidad serial: %lu baudios.\n\r",UartHandle.Init.BaudRate);
}

static void Error_Handler(void)
{
	/* Turn LED2 on */
	BSP_LED_On(LED2);
	while (1)
	{

	}
}
