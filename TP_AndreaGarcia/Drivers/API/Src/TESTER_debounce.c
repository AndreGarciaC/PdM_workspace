/*
 * API_debounce.c
 *
 *  Created on: 15 nov. 2021
 *      Author: Andrea García
 */

#include <TESTER_debounce.h>


static debounce_t debounceState;
static delay_t delay;

#define DELAY_TIME 40

bool_t debounceInit()
{
	debounceState = BUTTON_UP;
	delayInit(&delay, DELAY_TIME);

	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);


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
		if(!delayRead(&delay))
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
}

void buttonPressed()
{
	mefUpdate();
}


