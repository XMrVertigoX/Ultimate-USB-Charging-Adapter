/* 
 * Arduino library for controlling the MCP4151/415X/423X/425X digital potentiometer
 * 
 * Author: Caspar Friedrich
 */

#ifndef MCP4151_h
#define MCP4151_h

#include <inttypes.h>

// Address register. Uses full bit masks for easier combining.
const uint8_t ADDRESS_WIPER0 = 0b00000000; // 0x00
const uint8_t ADDRESS_WIPER1 = 0b00010000; // 0x01
const uint8_t ADDRESS_TCON   = 0b01000000; // 0x04
const uint8_t ADDRESS_STATUS = 0b01010000; // 0x05

// Command codes. Uses full bit masks for easier combining.
const uint8_t COMMAND_WRITE    = 0b00000000;
const uint8_t COMMAND_INCREASE = 0b00000100;
const uint8_t COMMAND_DECREASE = 0b00001000;
const uint8_t COMMAND_READ     = 0b00001100;

class MCP4151 {
	public:
		MCP4151(uint8_t spiAddress);

		void begin();

		// Increase or decrease wiper position. Wiper 0 by default for MCP4151
		void increase(uint8_t wiper = ADDRESS_WIPER0);
		void decrease(uint8_t wiper = ADDRESS_WIPER0);

	private:
		uint8_t _spiAddress;

		// writes a 8 bit message to the SPI bus.
		void write(uint8_t message);
};

#endif
