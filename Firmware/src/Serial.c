#include "Serial.h"

/*
 * Serial.c
 *
 * Created on: May 13, 2015
 * Author: Caspar Friedrich
 */

void serial_Init(void) {
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L = BAUD_PRESCALE;
}

void serial_Write(uint8_t data) {
	// Send data byte
	UDR0 = data;

	// Wait until transfer is done
	while (!(UCSR0A & (1 << UDRE0)))
		;
}
