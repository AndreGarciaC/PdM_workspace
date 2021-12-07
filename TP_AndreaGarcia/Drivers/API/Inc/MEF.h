/*
 * MEF.h
 *
 *  Created on: 7 dic. 2021
 *      Author: Andrea García
 */

#ifndef API_INC_MEF_H_
#define API_INC_MEF_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include <TESTER_uart.h>
#include "API_delay.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"

typedef uint32_t tick_t;
typedef bool bool_t;

bool_t mefInit();
bool_t ledInit();
void mefUpdate();

typedef enum{
   UART_stt,
   IO_stt,
   SD_stt,
   WIFI_stt,
   BLE_stt,
   ETH_stt
} demo_t;

#endif /* API_INC_MEF_H_ */
