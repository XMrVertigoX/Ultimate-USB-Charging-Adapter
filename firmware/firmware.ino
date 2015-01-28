/* 
 * Firmware prototype
 */

#include <SPI.h>
#include "./MCP413X.h"

// Digital potetiometer on GPIO 8 and 9
MCP413X potiA(8);
MCP413X potiB(9);

void setup () {
	// Start serial connection for debug output
	Serial.begin(9600);

	// Start SPI interface
	SPI.begin();
}

void loop () {
	potiA.increase();
	potiB.increase();

	delay(100);
}
