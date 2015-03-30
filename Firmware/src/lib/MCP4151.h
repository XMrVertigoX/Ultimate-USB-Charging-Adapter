/*
 * MCP4151.h
 *
 * Created on: 26.03.2015
 * Author: Caspar Friedrich
 */

#ifndef LIB_MCP4151_H_
#define LIB_MCP4151_H_

#include <inttypes.h>

// Address register. Uses full bit masks for easier combining.
#define MCP4151_WIPER0   0b00000000
#define MCP4151_WIPER1   0b00010000
#define MCP4151_TCON     0b01000000
#define MCP4151_STATUS   0b01010000

// Command codes. Uses full bit masks for easier combining.
#define MCP4151_WRITE    0b00000000
#define MCP4151_INCREASE 0b00000100
#define MCP4151_DECREASE 0b00001000
#define MCP4151_READ     0b00001100

class MCP4151 {
public:
	//static const uint8_t wiperMax = 255;
	//static const uint8_t wiperMin = 0;

	MCP4151(uint8_t ss);

	void decrease();
	void increase();
	//uint16_t read();
	uint16_t write(uint16_t data);

private:
	uint8_t _ssPin;
};

#endif /* LIB_MCP4151_H_ */
