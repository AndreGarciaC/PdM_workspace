/*
 * API_delay.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Andrea Garcia
 */

#include "API_delay.h"

void delayInit ( delay_t * delay, tick_t duration)
{
	delay->duration = duration;
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
			delay->startTime = elapsedTimeSinceStartup; //Finalizado un intervalo de delay, actualizo el startTime para dar comienzo a otro intervalo.
			isDurationOver = true;
		}
	}
	return isDurationOver;
}

void delayWrite ( delay_t * delay, tick_t duration)
{
	delay->duration = duration;
}
