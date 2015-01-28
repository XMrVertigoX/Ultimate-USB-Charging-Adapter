/* 
 * Firmware prototype
 */

#include <SPI.h>
#include "./MCP4X5X.h"

// Digital potetiometer on GPIO 8 and 9
MCP4X5X potiA(8);
MCP4X5X potiB(9);

void setup () {
	// Start serial connection for debug output
	Serial.begin(9600);

	// Start SPI interface
	SPI.begin();
}

void loop () {

}
