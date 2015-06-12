#include "Serial.h"

/*
 * Serial.c
 *
 * Created on: May 13, 2015
 * Author: Caspar Friedrich
 */

#include <math.h>
#include <string.h>

void Serial_init(void) {
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L = BAUD_PRESCALE;
}

void Serial_write(uint8_t data) {
	// Send data byte
	UDR0 = data;

	// Wait until transfer is done
	while (!(UCSR0A & (1 << UDRE0)))
		;
}

void Serial_print(uint8_t string[]) {
	int i;

	for (i = 0; i < strlen(string); i++) {
		Serial_write(string[i]);
	}
}

void Serial_printNumeric(uint8_t value, uint8_t base) {
	if (value == 0) {
		Serial_print("0");
	} else {
		uint8_t str[(uint8_t) log10(value) + 1];
		itoa(value, str, base);
		Serial_print(str);
	}
}
