/*
 * Main.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

// Read mode interrupt flag
bool readMode = false;

// ADC values
uint16_t USB0, USB1;

int main(void) {
	// TODO: Read values from eeprom

	//SPI_Init();

	while (1) {
		if (readMode) {
			// TODO: Neue Spannung einlesen, im eeprom und in USB0/USB1 speichern.
		}

		// TODO: Regelkram
	}

	// Second loop to prevent system failures
	while (1)
		;
}
