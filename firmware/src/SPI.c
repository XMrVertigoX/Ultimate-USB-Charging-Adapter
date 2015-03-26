/*
 * SPI.c
 *
 * Created on: 26.03.2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>
#include "SPI.h"

#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK  7
#define DDR_SPI DDRB

void SPI_MasterInit(void) {
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);

	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_MasterTransmit(uint8_t data) {
	/* Start transmission */
	SPDR = data;

	/* Wait for transmission complete */
	while (!(SPSR & (1 << SPIF)))
		;
}
