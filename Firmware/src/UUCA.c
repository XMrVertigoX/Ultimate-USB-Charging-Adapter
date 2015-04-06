#include "UUCA.h"

/*
 * UUCA.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>

void init(void) {
	adcInit();
	spiInit();

	// SS pins for the potis as outputs
	DDRB |= (1 << POTI0) | (1 << POTI1);
}

void transmit(uint8_t pin, uint8_t data) {
	// Set slave pin low
	PORTB &= ~(1 << pin);

	// Set slave pin high
	PORTB |= (1 << pin);
}
