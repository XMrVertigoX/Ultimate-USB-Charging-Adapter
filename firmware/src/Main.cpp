/*
 * Main.c
 *
 * Created on: 26.03.2015
 * Author: Caspar Friedrich
 */

#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"
#include "lib/MCP4151.h"

//#define DD_MOSI 5
//#define DD_MISO 6
//#define DD_SCK  7
//#define DDR_SPI DDRB
//
//void SPI_MasterInit(void) {
//	/* Set MOSI and SCK output, all others input */
//	DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);
//	/* Enable SPI, Master, set clock rate fck/16 */
//	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
//}
//
//void SPI_MasterTransmit(uint8_t data) {
//	/* Start transmission */
//	SPDR = data;
//	/* Wait for transmission complete */
//	while (!(SPSR & (1 << SPIF)))
//		;
//}

int main() {
	SPI_MasterInit();

	//DDRC = 0xFF; //PORTC as output, used for Slave Selections

	while (true) {
//		PORTC = 0;
//		_delay_ms(1000);
//		//SPI_MasterInit();
//		SPI_MasterTransmit(0xFF);
//		PORTC = 255;
//		_delay_ms(1000);
//
//		PORTC = 0;
//		_delay_ms(1000);
//		//SPI_MasterInit();
//		SPI_MasterTransmit(0x00);
//		PORTC = 255;
//		_delay_ms(1000);

		SPI_MasterTransmit(0b10101010);
	}

	// Second infinite loop to prevent system crash
	while (true)
		;

	return 0;
}
