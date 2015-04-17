/*
 * ADC.h
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc_Init(void);

uint16_t adc_Read(uint8_t adc);

#endif /* ADC_H_ */
