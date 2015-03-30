/*
 * ADC.h
 *
 * Created on: Mar 30, 2015
 * Author: Caspar Friedrich
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LIB_ADC_H_
#define LIB_ADC_H_

#include <inttypes.h>

void ADC_Init(uint8_t *adcPins);
uint16_t ADC_Read(uint8_t adcPin);

#endif /* LIB_ADC_H_ */

#ifdef __cplusplus
}
#endif
