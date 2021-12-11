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
#include <stdio.h>
#include <string.h>
#include <TESTER_debounce.h>
#include "main.h"

UART_HandleTypeDef UartHandle;

void Uart_Init(void);
void uartSendMsg(uint8_t *pstring);
bool uartReadMsgPR310();

char rxBuff[0xFF];

#endif /* API_DELAY_H_ */
