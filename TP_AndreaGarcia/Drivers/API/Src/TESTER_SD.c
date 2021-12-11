/*
 * TESTER_SD.c
 *
 *  Created on: 7 dic. 2021
 *      Author: Andrea García
 */

#ifndef API_SRC_TESTER_SD_C_
#define API_SRC_TESTER_SD_C_

#include <TESTER_SD.h>

SPI_HandleTypeDef hspi1;


static void Error_Handler(void);

void SD_Rutine(void)
{
	fres = f_mount(&fs, "", 0);
	if (fres == FR_OK) {
		uartSendMsg((uint8_t *)"Micro SD card is mounted successfully!\n");
	} else if (fres != FR_OK) {
		uartSendMsg((uint8_t *)"Micro SD card's mount error!\n");
	}

	/* Open file to read */
	fres = f_open(&fil, "config.txt", FA_READ);
	if (fres == FR_OK) {
		uartSendMsg((uint8_t *)"Archivo config encontrado.\n");
		fres = f_close(&fil);
			if (fres == FR_OK) {
				uartSendMsg((uint8_t *)"The file is closed.\n");
			} else if (fres != FR_OK) {
				uartSendMsg((uint8_t *)"The file was not closed.\n");
			}
	} else if (fres != FR_OK) {
		uartSendMsg((uint8_t *)"No existe archivo config!\n");
	}

	f_mount(NULL, "", 1);
	if (fres == FR_OK) {
		uartSendMsg((uint8_t *)"The Micro SD card is unmounted!\n");
	} else if (fres != FR_OK) {
		uartSendMsg((uint8_t *)"The Micro SD was not unmounted!");
	}
}



void MX_SPI1_Init(void)
{
	/* SPI1 parameter configuration*/
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

}

static void Error_Handler(void)
{
	/* Turn LED2 on */
	BSP_LED_On(LED2);
	while (1)
	{

	}
}

#endif

