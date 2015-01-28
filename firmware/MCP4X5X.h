#ifndef MCP4X5X_h
#define MCP4X5X_h

#include <inttypes.h>

// Address register
const uint8_t ADDRESS_WIPER0 = 0b00000000;
const uint8_t ADDRESS_WIPER1 = 0b00010000;
const uint8_t ADDRESS_TCON   = 0b00040000;
const uint8_t ADDRESS_STATUS = 0b00050000;

// Commands
const uint8_t COMMAND_WRITE    = 0b00000000;
const uint8_t COMMAND_INCREASE = 0b00001000;
const uint8_t COMMAND_DECREASE = 0b00000100;
const uint8_t COMMAND_READ     = 0b00001100;

class MCP4X5X {
	public:
		MCP4X5X(uint8_t spiAddress);

		void begin();

		// Increase or decrease wiper position. choose wiper 0 by default for MCP4151
		void increase(uint8_t wiper = ADDRESS_WIPER0);
		void decrease(uint8_t wiper = ADDRESS_WIPER0);

	private:
		uint8_t _spiAddress;

		// Send 8 (increase/decrease) bit or 16 (read/write) bit messages
		void write8(uint8_t address, uint8_t command, uint8_t data);
		void write16(uint8_t address, uint8_t command, uint16_t data);

		// Clear address/data/command data
		uint8_t clearAddress(uint8_t address);
		uint8_t clearCommand(uint8_t command);
		uint8_t clearData8(uint8_t data);
		uint16_t clearData16(uint16_t data);
};

#endif
