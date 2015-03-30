#include "SPI.h"

/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>

void SPI_Init(uint8_t *ssPins) {
	// Set MOSI, SCK and SS as output
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2) | (1 << PB1);

	// Set SS to high
	PORTB |= (1 << PB2) | (1 << PB1);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_Transmit(uint8_t ss, uint8_t data) {
	// Select slave
	PORTB &= ~(1 << ss);

	// Send data
	SPDR = data;

	// Wait for transmition complete
	while (!(SPSR & (1 << SPIF)))
		;

	// SS to high
	PORTB |= (1 << ss);
}

