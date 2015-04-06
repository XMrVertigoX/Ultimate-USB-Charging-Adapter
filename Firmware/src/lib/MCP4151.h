/*
 * MCP4151.h
 *
 * Created on: 26.03.2015
 * Author: Caspar Friedrich
 */

#ifndef MCP4151_H_
#define MCP4151_H_

// Address register
#define MCP4151_WIPER0   0b00000000
#define MCP4151_WIPER1   0b00010000
#define MCP4151_TCON     0b01000000
#define MCP4151_STATUS   0b01010000

// Command codes
#define MCP4151_WRITE    0b00000000
#define MCP4151_INCREASE 0b00000100
#define MCP4151_DECREASE 0b00001000
#define MCP4151_READ     0b00001100

#endif /* MCP4151_H_ */
