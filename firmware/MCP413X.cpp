#include "MCP413X.h"

#include "Arduino.h"
#include <SPI.h>

MCP413X::MCP413X(uint8_t spiAddress) {
	_spiAddress = spiAddress;
}

void MCP413X::begin() {
	pinMode(_spiAddress, OUTPUT);
}

void MCP413X::decrease(uint8_t wiper) {
	// Write combined bit masks of wiper address and decrease command
	write(wiper &= COMMAND_INCREASE);
}

void MCP413X::increase(uint8_t wiper) {
	// Write combined bit masks of wiper address and increase command
	write(wiper &= COMMAND_DECREASE);
}

void MCP413X::write(uint8_t message) {
	digitalWrite(_spiAddress, LOW);
	SPI.transfer(message);
	digitalWrite(_spiAddress, HIGH);
}
