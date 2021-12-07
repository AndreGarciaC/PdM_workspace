/*
 * TESTER_SD.h
 *
 *  Created on: 7 dic. 2021
 *      Author: andrea
 */

#ifndef API_INC_TESTER_SD_H_
#define API_INC_TESTER_SD_H_

//#include "fatfs_sd.h"
#include "string.h"
#include "stdio.h"

SPI_HandleTypeDef hspi1;
FATFS fs;
FATFS *pfs;
FIL fil;
FRESULT fres;
DWORD fre_clust;
uint32_t totalSpace, freeSpace;
char buffer[100];

#endif /* API_INC_TESTER_SD_H_ */
