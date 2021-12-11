/*
 * TESTER_SD.h
 *
 *  Created on: 7 dic. 2021
 *      Author: andrea
 */

#ifndef API_INC_TESTER_SD_H_
#define API_INC_TESTER_SD_H_

#include <TESTER_uart.h>
#include "../../../FATFS/App/fatfs.h"

#include "fatfs_sd.h"
#include "string.h"
#include "stdio.h"
#include "main.h"

SPI_HandleTypeDef hspi1;
FATFS fs;
FATFS *pfs;
FIL fil;
FRESULT fres;
DWORD fre_clust;
uint32_t totalSpace, freeSpace;
char buffer[100];

void MX_GPIO_Init(void);
void MX_SPI1_Init(void);
void SD_Rutine(void);

#endif /* API_INC_TESTER_SD_H_ */
