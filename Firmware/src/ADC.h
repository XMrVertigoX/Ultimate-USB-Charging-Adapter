/*
 * ADC.h
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <avr/io.h>

#define ADC_IN_A  PC0
#define ADC_IN_B  PC1
#define ADC_OUT_A PC2
#define ADC_OUT_B PC3

void ADC_init(void);

uint16_t ADC_read(uint8_t channel);

#endif /* ADC_H_ */
