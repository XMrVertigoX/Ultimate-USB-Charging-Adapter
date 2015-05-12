/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include "SPI.h"

void spi_Init(void) {
	// Set MOSI and SCK as outputs
	DDRB |= _BV(MOSI) | _BV(SCK) | _BV(POTI0) | _BV(POTI1);

	// Enable master SPI at clock rate Fck/16
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0);

	// Set both SS lines high
	PORTB |= _BV(POTI0) | _BV(POTI1);
}

void spi_Transfer(uint8_t data, uint8_t poti) {
	// Set SS pin low
	PORTB &= ~(_BV(poti));

	// Send data byte
	SPDR = data;

	// Wait until transfer is done
	while (!(SPSR & _BV(SPIF)))
		;

	// Set SS pin high
	PORTB |= _BV(poti);
}
