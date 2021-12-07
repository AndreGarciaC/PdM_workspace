/*
 * API_debounce.c
 *
 *  Created on: 15 nov. 2021
 *      Author: Andrea García
 */

#include <TESTER_uart.h>
#include "API_debounce.h"
#include "API_delay.h"
#include "MEF.h"

static debounce_t debounceState;
static delay_t delay;
static delay_t led1Delay;
static delay_t led2Delay;
static delay_t led3Delay;
static bool_t pbFlag;

static uint8_t miString[]  = "\r Cambio de frecuencia a 500ms \n\r";
static uint8_t miString2[]  = "\r Cambio de frecuencia variable \n\r";

void buttonPressed();
void buttonReleased();
void leds();

#define DELAY_TIME 40

bool_t debounceInit()
{
	debounceState = BUTTON_UP;
	delayInit(&delay, DELAY_TIME);

	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);


	return true;
}

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

void debounceUpdate()
{
	switch(debounceState)
	{
		case BUTTON_UP:
			if(BSP_PB_GetState(BUTTON_USER))
			{
				delayRead(&delay);
				debounceState = BUTTON_FALLING;
			}
			break;
		case BUTTON_FALLING:
			if(delayRead(&delay))
			{
				if(BSP_PB_GetState(BUTTON_USER))
				{
					buttonPressed();
					debounceState = BUTTON_DOWN;
				}
				else
				{
					debounceState = BUTTON_UP;
				}
			}
			break;
		case BUTTON_DOWN:
			if(!BSP_PB_GetState(BUTTON_USER))
			{
				delayRead(&delay);
				debounceState = BUTTON_RAISING;
			}
			break;
		case BUTTON_RAISING:
			if(delayRead(&delay))
			{
				if(!BSP_PB_GetState(BUTTON_USER))
				{
					debounceState = BUTTON_UP;
				}
				else
				{
					debounceState = BUTTON_DOWN;
				}
			}
			break;
	}
	leds();
}

void buttonPressed()
{

	pbFlag = !pbFlag;
	if(pbFlag == true)
		{
			BSP_LED_Off(LED1);
			BSP_LED_Off(LED2);
			BSP_LED_Off(LED3);
			delayInit(&led1Delay,500);
			delayInit(&led2Delay,500);
			delayInit(&led3Delay,500);
			mefUpdate();
		}
	else if (pbFlag == false)
		{
			delayInit(&led1Delay,100);
			delayInit(&led2Delay,500);
			delayInit(&led3Delay,1000);
			uartSendMsg((uint8_t *)miString2);
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
