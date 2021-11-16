/*
 * API_delay.h
 *
 *  Created on: 15 nov. 2021
 *      Author: Andrea García
 */

#ifndef API_DEBOUNCE_H_
#define API_DEBOUNCE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"

typedef uint32_t tick_t;
typedef bool bool_t;

bool_t debounceInit();
bool_t ledInit();
void debounceUpdate();


typedef enum{
   BUTTON_UP,
   BUTTON_FALLING,
   BUTTON_DOWN,
   BUTTON_RAISING
} debounce_t;

#endif /* API_DELAY_H_ */
