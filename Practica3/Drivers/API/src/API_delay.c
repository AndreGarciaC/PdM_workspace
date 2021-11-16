/*
 * API_delay.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Andrea Garcia & Gonzalo Vila
 */

#include "API_delay.h"

void delayInit ( delay_t * delay, tick_t duration)
{
	if(delay == 0 || duration < 0 || duration > MAX_DELAY) //Puntero no sea cero
		while(1);
	delay->duration = duration;
	delay->running = 0;
}

bool_t delayRead ( delay_t * delay)
{
	bool_t isDurationOver = false;

	if (delay==0)
		while(1);

	if (!delay->running)
	{
		delay->startTime = HAL_GetTick();
		delay->running = true;
	}
	else
	{
		if (((tick_t)HAL_GetTick() - delay->startTime) >= delay->duration)
		{
			isDurationOver = true;
			delay->running = 0;
		}
	}
	return isDurationOver;
}

void delayWrite ( delay_t * delay, tick_t duration)
{
	delay->duration = duration;
}
