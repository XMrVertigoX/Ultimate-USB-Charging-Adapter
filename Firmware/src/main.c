/*
 * Main.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#include "UUCA.h"

// Read mode interrupt flag
bool readMode = false;

int main(void) {
	init();

	// TODO: Read values from eeprom

	while (1) {
		if (readMode) {
			// TODO: Neue Spannung einlesen, in eeprom und in laufzeitvariable speichern.
		}

		// TODO: Regelkram
	}

	// Second loop to prevent system failures
	while (1)
		;
}
