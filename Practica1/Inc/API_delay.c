/*
 * API_delay.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Andrea Garcia & Gonzalo Vila
 */

#include "API_delay.h"

void delayInit ( delay_t * delay, tick_t duration)
{
	delay->duration = duration;
	delay->running = 0;
}

bool_t delayRead ( delay_t * delay)
{
	tick_t elapsedTimeSinceStartup = HAL_GetTick();
	bool_t isDurationOver = false;
	if (!delay->running)
	{
		delay->startTime = elapsedTimeSinceStartup;
		delay->running = true;
	}
	else
	{
		if ((elapsedTimeSinceStartup - delay->startTime) >= delay->duration)
		{
			delay->startTime = elapsedTimeSinceStartup;
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
