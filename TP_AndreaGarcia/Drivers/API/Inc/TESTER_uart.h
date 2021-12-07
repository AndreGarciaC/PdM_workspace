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
#include "string.h"
#include "main.h"

bool uartInit();
void uartSendMsg(uint8_t *pstring);
void uartReadMsg();

#endif /* API_DELAY_H_ */
