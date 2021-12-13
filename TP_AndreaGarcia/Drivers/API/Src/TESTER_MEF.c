/*
 * MEF.c
 *
 *  Created on: 7 dic. 2021
 *      Author: andrea
 */

#ifndef API_SRC_MEF_C_
#define API_SRC_MEF_C_

#include <TESTER_MEF.h>
static demo_t demoState;
static bool_t rxFlag;


#define DELAY_RX 3000
static delay_t ansDelay;
static void test();



static delay_t led1Delay;
static delay_t led2Delay;
static delay_t led3Delay;

bool_t ledInit()
{
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);

	delayInit (&led1Delay, 100);
	delayInit (&led2Delay, 500);
	delayInit (&led3Delay, 1000);

	return true;
}

bool_t mefInit()
{
	demoState = UART_stt;
	rxFlag = false;
	delayInit (&ansDelay, DELAY_RX);
	return true;
}


void mefUpdate()
{
	uartSendMsg((uint8_t *)("\r DEMO GENERAL PRUEBAS PR-310\n\r"));
	switch(demoState)
	{
	case UART_stt:
		uartSendMsg((uint8_t *)"\r Prueba: Serial\n\r");
		test();
		demoState = IO_stt;
	case IO_stt:
		uartSendMsg((uint8_t *)("\r Prueba: Entradas y salidas verificadas \n\r"));
		test();
		demoState = SD_stt;
	case SD_stt:
		SD_Rutine();
		uartSendMsg((uint8_t *)("\r Prueba: Micro SD verificada \n\r"));
		test();
		demoState = WIFI_stt;
	case WIFI_stt:
		uartSendMsg((uint8_t *)("\r Prueba: WiFi verificado \n\r"));
		test();
		demoState = BLE_stt;
	case BLE_stt:
		uartSendMsg((uint8_t *)("\r Prueba: BLE verificado \n\r"));
		test();
		demoState = ETH_stt;
	case ETH_stt:
		uartSendMsg((uint8_t *)("\r Prueba: Ethernet verificado \n\r"));
		test();
		leds();
		break;
	}
}

//void demoSuccess()
//{
//	if(scsFlag)
//	{
//		uartSendMsg((uint8_t *)("\r Exito \n\r"));
//		BSP_LED_Toggle(LED1);
//		BSP_LED_Off(LED2);
//	}
//	else if (!scsFlag)
//	{
//		uartSendMsg((uint8_t *)("\r Fallo \n\r"));
//		BSP_LED_Toggle(LED2);
//		BSP_LED_Off(LED1);
//	}
//}

static void test()
{
	while(!delayRead(&ansDelay))
	{
		rxFlag=uartReadMsgPR310();
	}
	uartSendMsg((uint8_t *)("\r Timeout\n\r"));
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
