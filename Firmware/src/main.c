/*
 * Main.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#include "lib/SPI.h"

// Read mode interrupt flag
bool readMode = false;

int main(void) {
	// Initialize SPI bus
	spi_Init();

	// Initialize SPI queue
	spiQueue spiQueue;
	spiQueue_Init(&spiQueue);

	// TODO: Read values from eeprom

	while (1) {
		// Tranfer next SPI message if bus is ready
		if (spi_IsReady()) {
			spiQueue_TransferNext(&spiQueue);
		}

		if (readMode) {
			// TODO: Neue Spannung einlesen, und als ADC Values im EEPROM und in den Laufzeitvariablen speichern.
		}

		// TODO: Regelkram
	}

	// Second loop to prevent system failures
	while (1)
		;
}
