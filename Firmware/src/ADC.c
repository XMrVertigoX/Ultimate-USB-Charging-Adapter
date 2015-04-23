/*
 * ADC.c
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

#include "ADC.h"

void adc_Init(void) {
	// Enable the ADC
	ADCSRA |= _BV(ADEN);
}

uint16_t adc_Read(uint8_t channel) {
	// Setup conversion: Use AVCC as reference.
	ADMUX |= _BV(REFS0) | channel;

	// Start the conversion
	ADCSRA |= _BV(ADSC);

	// Wait for conversion to finish
	while ((ADCSRA & _BV(ADSC)))
		;

	// Return ADC value register
	return ADC;
}
