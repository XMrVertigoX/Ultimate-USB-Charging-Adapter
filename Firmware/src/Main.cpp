/*
 * Main.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#include "lib/SPI.h"

bool readMode = false;
float USB0, USB1;

int main(void) {
	// Read values from eeprom

	//SPI_Init();

	while (1) {
		if (readMode) {
			// Neue Spannung einlesen, im eeprom und in USB0/USB1 speichern.
		}

		// Regelkram
	}

	// Second loop to prevent system failures
	while (1)
		;
}
