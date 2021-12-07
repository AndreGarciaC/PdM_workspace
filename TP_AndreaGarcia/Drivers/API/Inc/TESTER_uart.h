/*
 * API_delay.h
 *
 *  Created on: 27 nov. 2021
 *      Author: Andrea García & Gonzalo Vila
 */

#ifndef TESTER_UART_H_
#define TESTER_UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "API_debounce.h"

#define DELAY_TIME 100

char ans[];

bool uartInit();
void uartSendMsg(uint8_t *pstring);
void uartReadMsg();

#endif /* API_DELAY_H_ */
