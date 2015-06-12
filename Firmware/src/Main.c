#include "Main.h"

/*
 * Main.c
 */

struct {
	bool readMode; // Read mode interrupt flag
} flags;

int main(void) {
	// Initialize ADCs
	ADC_init();

	// Initialize SPI bus
	SPI_init();

	// Initialize serial connection
	Serial_init();

	// TODO: Read values from EEPROM

	// Enable interrupts
	sei();

	uint8_t i = 0;
	bool rising = true;

	// Infinite loop
	for (;;) {
		// Read new voltages if flag is present
		if (flags.readMode) {
			// TODO: Read current voltage and save in runtime and EEPROM

			// Turn off read mode when done
			flags.readMode = false;
		}

		// TODO: Regulator stuff

		Serial_print("Counter: ");
		Serial_printNumeric(i, 10);
		Serial_print("\r\n");

		if (rising) {
			SPI_transfer(MCP4151_8_INCREASE, POTI0);
			SPI_transfer(MCP4151_8_INCREASE, POTI1);
			i++;
		} else {
			SPI_transfer(MCP4151_8_DECREASE, POTI0);
			SPI_transfer(MCP4151_8_DECREASE, POTI1);
			i--;
		}

		if (i == 255) {
			rising = false;
		} else if (i == 0) {
			rising = true;
		}

		_delay_ms(250);
	}

	//Disable interrupts in case of system failure
	cli();

	// Second loop to prevent system failures
	for (;;)
		;
}
