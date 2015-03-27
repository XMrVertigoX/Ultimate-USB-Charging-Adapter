// SPI master

#include <inttypes.h>
#include <util/delay.h>

#include "lib/MCP4151.h"
#include "SPI.h"

int main(void) {
	// Initialize master SPI
	SPIMasterInit();

	uint8_t counter = 0;

	while (1) {
		SPIMasterSend(counter++);
	}

	// Second loop to prevent system failures
	while (1)
		;
}
