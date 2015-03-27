/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>
#include "SPI.h"

void SPIMasterInit(void) {
	// Set MOSI, SCK and SS as output
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);

	// Set SS to high
	PORTB |= (1 << PB2);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPIMasterSend(uint8_t data) {
	// Select slave
	PORTB &= ~(1 << PB2);

	// Send data
	SPDR = data;

	// Wait for transmition complete
	while (!(SPSR & (1 << SPIF)))
		;
	// SS to high
	PORTB |= (1 << PB2);
}
