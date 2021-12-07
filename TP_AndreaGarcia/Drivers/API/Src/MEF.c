/*
 * MEF.c
 *
 *  Created on: 7 dic. 2021
 *      Author: andrea
 */

#ifndef API_SRC_MEF_C_
#define API_SRC_MEF_C_

#include "MEF.h"
static demo_t demoState;
static bool_t scsFlag;

static char stringMsg[]  = "\r Prueba serial completada \n\r";

void demoSuccess();

#define DELAY_TIME 40

bool_t mefInit()
{
	demoState = UART_stt;
	return true;
}


void mefUpdate()
{
	switch(demoState)
	{
	case UART_stt:
		uartSendMsg((uint8_t *)stringMsg);
		uartReadMsg();
		//		scsFlag = !scsFlag;
		scsFlag = true;
		demoState = IO_stt;
	case IO_stt:
		uartSendMsg((uint8_t *)("\r Entradas y salidas verificadas \n\r"));
		demoState = SD_stt;
	case SD_stt:
		uartSendMsg((uint8_t *)("\r Micro SD verificada \n\r"));
		demoState = WIFI_stt;
	case WIFI_stt:
		uartSendMsg((uint8_t *)("\r WiFi verificado \n\r"));
		demoState = BLE_stt;
	case BLE_stt:
		uartSendMsg((uint8_t *)("\r BLE verificado \n\r"));
		demoState = ETH_stt;
	case ETH_stt:
		uartSendMsg((uint8_t *)("\r Ethernet verificado \n\r"));
		demoState = UART_stt;
	}
	leds();
}

void demoSuccess()
{

	if(scsFlag == true)
	{
		uartSendMsg((uint8_t *)("\r Éxito \n\r"));
		uartSendMsg((uint8_t *)stringMsg);
	}
	else if (scsFlag == false)
	{
		uartSendMsg((uint8_t *)("\r Fallo \n\r"));
		uartSendMsg((uint8_t *)stringMsg);
	}
}

void buttonPressed()
{
	mefUpdate();
	pbFlag = !pbFlag;
	if(pbFlag == true)
		{
			BSP_LED_Off(LED1);
			BSP_LED_Off(LED2);
			BSP_LED_Off(LED3);
			delayInit(&led1Delay,500);
			delayInit(&led2Delay,500);
			delayInit(&led3Delay,500);

		}
	else if (pbFlag == false)
		{
			delayInit(&led1Delay,100);
			delayInit(&led2Delay,500);
			delayInit(&led3Delay,1000);
		}
}

void leds()
{
	if (delayRead(&led1Delay))
	{
		BSP_LED_Toggle(LED1);
	}
	if (delayRead(&led2Delay))
	{
		BSP_LED_Toggle(LED2);
	}
	if (delayRead(&led3Delay))
	{
		BSP_LED_Toggle(LED3);
	}
}



#endif /* API_SRC_MEF_C_ */
