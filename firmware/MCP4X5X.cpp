#include "MCP4X5X.h"

#include "Arduino.h"
#include <SPI.h>

MCP4X5X::MCP4X5X(uint8_t spiAddress) {
	_spiAddress = spiAddress;
}

void MCP4X5X::begin() {
	pinMode(_spiAddress, OUTPUT);
}

void MCP4X5X::increase(uint8_t wiper) {

}

void MCP4X5X::decrease(uint8_t wiper) {

}
