/*
 * Main.c
 */

#include <inttypes.h>

#include <avr/io.h>

#include <util/delay.h>

#include "lib/UUCA.h"

int main(void) {
	SPI_Init();

	uint8_t counter = 0;

	while (1) {
		SPI_Transmit(PB1, counter++);
		SPI_Transmit(PB2, counter++);
	}

	// Second loop to prevent system failures
	while (1)
		;
}
