#include "MCP4151.h"

#include "Arduino.h"
#include <SPI.h>

MCP4151::MCP4151(uint8_t spiAddress) {
	_spiAddress = spiAddress;
}

void MCP4151::begin() {
	pinMode(_spiAddress, OUTPUT);
}

void MCP4151::decrease(uint8_t wiper) {
	// Write combined bit masks of wiper address and decrease command
	write(wiper |= COMMAND_INCREASE);
}

void MCP4151::increase(uint8_t wiper) {
	// Write combined bit masks of wiper address and increase command
	write(wiper |= COMMAND_DECREASE);
}

void MCP4151::write(uint8_t message) {
	digitalWrite(_spiAddress, LOW);
	SPI.transfer(message);
	digitalWrite(_spiAddress, HIGH);
}
