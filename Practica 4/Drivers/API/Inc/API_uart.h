/*
 * API_delay.h
 *
 *  Created on: 27 nov. 2021
 *      Author: Andrea García & Gonzalo Vila
 */

#ifndef API_UART_H_
#define API_UART_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"


bool uartInit();
void uartSendString(uint8_t *pstring);

#endif /* API_DELAY_H_ */
