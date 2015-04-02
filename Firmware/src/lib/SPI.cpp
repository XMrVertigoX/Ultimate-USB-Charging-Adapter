#include "SPI.h"

/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>

#define MOSI PB3
//#define MISO
#define SCK PB5
#define PORT PORTB

void SPI_Init() {
	// Set output and clock pin as output
	DDRB |= (1 << MOSI) | (1 << SCK);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_AddSlave(uint8_t ss) {
	// Set SS as output
	DDRB |= (1 << ss);

	// Set SS to high
	PORT |= (1 << ss);
}

void SPI_Transmit(uint8_t ss, uint8_t *data, uint8_t quantity) {
	// Select slave
	PORT &= ~(1 << ss);

	for (int i = 0; i < quantity; i++) {
		// Send data
		SPDR = data[i];

		// Wait for transmition complete
		while (!(SPSR & (1 << SPIF)))
			;
	}

	// SS to high
	PORT |= (1 << ss);
}

