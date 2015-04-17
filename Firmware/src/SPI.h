/*
 * SPI.h - SPI controller library for the UUCA
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include <avr/io.h>

#define POTI0 PB1
#define POTI1 PB2

/*
 * Initializes all SPI related hardware.
 */
void spi_Init(void);

/*
 * Tranfers one data byte.
 */
void spi_Transfer(uint8_t data, uint8_t poti);

#endif /* SPI_H_ */
