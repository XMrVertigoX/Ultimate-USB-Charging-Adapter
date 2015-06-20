#include "Serial.h"

/*
 * Serial.c
 *
 * Created on: May 13, 2015
 * Author: Caspar Friedrich
 */

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
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

void Serial_print(char *str) {
	int i;

	for (i = 0; i < strlen(str); i++) {
		// Print a space if char is not ascii
		if (isascii(str[i])) {
			Serial_write(str[i]);
		} else {
			// Write a space for every non-ascii character
			Serial_write(0x20);
		}
	}
}

void Serial_println(char *str) {
	Serial_print(str);
	Serial_print("\r\n");
}

void Serial_printInteger(int val, uint8_t base) {
	uint8_t digits;

	// Calculate digits
	if (val == 0) {
		digits = 1;
	} else {
		digits = (uint8_t) log10(abs(val)) + 1;
	}

	// Create an empty char buffer matching the digits and add two for the terminating zero and the sign
	char str[digits + 2];

	itoa(val, str, base);

	Serial_print(str);
}
