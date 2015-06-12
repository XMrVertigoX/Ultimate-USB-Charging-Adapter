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

#define POTI0 PB0
#define POTI1 PB1

#define SS    PB2
#define MOSI  PB3
#define MISO  PB4
#define SCK   PB5

/*
 * Initializes all SPI related hardware.
 */
void SPI_init(void);

/*
 * Transfers one data byte.
 */
void SPI_transfer(uint8_t data, uint8_t poti);

#endif /* SPI_H_ */
