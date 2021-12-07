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
		break;
	}
	leds();
}

void demoSuccess()
{

	if(scsFlag == true)
	{
		memset(stringMsg,"\r Éxito \n\r",strlen(stringMsg));
		uartSendMsg((uint8_t *)stringMsg);
	}
	else if (scsFlag == false)
	{
		memset(stringMsg,"\r Fallo \n\r",strlen(stringMsg));
		uartSendMsg((uint8_t *)stringMsg);
	}
}



#endif /* API_SRC_MEF_C_ */
