#include "Events.h"

/*
 * Events.c
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

#include <avr/io.h>
#include <avr/interrupt.h>

void events_Init(void) {
	// Turn on the Pull-up
	PORTD |= _BV(PORTD2);

	// Turn on interrupt(s)
	EIMSK |= _BV(INT0);
}

ISR (INT0_vect) {
	/* interrupt code here */
}
