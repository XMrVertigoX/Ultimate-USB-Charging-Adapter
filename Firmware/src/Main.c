/*
 * Main.c
 */

#include <stdbool.h>
#include <stdint.h>

#include <avr/interrupt.h>

#include "ADC.h"
#include "Events.h"
#include "SPI.h"

#include "lib/MCP4151.h"

struct {
	// Read mode interrupt flag
	bool readMode;
} flags;

int main(void) {
	//Initialize interrupts
	events_Init();

	// Initialize ADCs
	adc_Init();

	// Initialize SPI bus
	spi_Init();

	// TODO: Read values from EEPROM

	// Enable interrupts
	sei();

	// Counter
	uint8_t i = 0;

	// Infinite loop
	for (;;) {
		// Read new voltages if flag is present
		if (flags.readMode) {
			// TODO: Read current voltage and save in runtime and EEPROM

			// Turn off read mode when done
			flags.readMode = false;
		}

		// TODO: Regulator stuff

		if (i < 255) {
			spi_Transfer(i, POTI0);
			spi_Transfer(i, POTI1);
			i++;
		}
	}

	//Disable interrupts in case of system failure
	cli();

	// Second loop to prevent system failures
	for (;;)
		;
}
