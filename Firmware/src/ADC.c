#include "ADC.h"

/*
 * ADC.c
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

void ADC_init(void) {
	// Setup conversion: Use AVCC as reference.
	ADMUX = (1 << REFS0);

	// Enable the ADC (ADEN) and set the prescale factor for conversion frequency (125kHz) (ADPS2...0)
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_read(uint8_t channel) {
	// Check if channel value is valid
	if (channel > 8) {
		return 0xFFFF;
	}

	// Set ADC
	ADMUX |= channel;

	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to finish
	while ((ADCSRA & (1 << ADSC)))
		;

	// Reset ADC mux (set MUX3...0 to zero)
	ADMUX &= 0xF0;

	// Return ADC value register
	return ADC;
}
