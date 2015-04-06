#include "SPI.h"

/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>

void spiInit(void) {
	// Set MOSI (PB3) and SCK (PB5) as outputs
	DDRB |= (1 << PB3) | (1 << PB5);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void spiTransmit(uint8_t data) {
	// Send data
	SPDR = data;

	// Wait for transmition complete.
	while (!(SPSR & (1 << SPIF)))
		;
}
