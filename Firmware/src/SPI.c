/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include "SPI.h"

#define MOSI PB3
#define SCK  PB5

void spi_Init(void) {
	// Set MOSI and SCK as outputs
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << POTI0) | (1 << POTI1);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

	// Set both SS lines high
	PORTB |= (1 << POTI0) | (1 << POTI1);
}

void spi_Transfer(uint8_t data, uint8_t poti) {
	// Set SS pin low
	PORTB &= ~(1 << poti);

	// Send data byte
	SPDR = data;

	// Wait until transfer is done
	while (!(SPSR & (1 << SPIF)))
		;

	// Set SS pin high
	PORTB |= (1 << poti);
}
