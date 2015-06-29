#include "ADC.h"

/*
 * ADC.c
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

void ADC_initializeHardware(void) {
	/* Setup ADC.
	 * ADEN: Enable the ADC
	 * ADPS2...0: Set the prescale factor for conversion to 64 (125kHz) */
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	/* Setup conversion.
	 * REFS0: Use AVCC as reference. */
	ADMUX |= (1 << REFS0);
}

uint16_t ADC_startConversion(uint8_t channel) {
	// Check if channel value is valid
	if (channel > 8) {
		return 0xFC00;
	}

	// Set ADC
	ADMUX |= channel;

	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to finish
	sleep(!(ADCSRA & (1 << ADSC)));

	// Reset ADC mux (set MUX3...0 to zero)
	ADMUX &= 0xF0;

	// Return ADC value register
	return ADC;
}
