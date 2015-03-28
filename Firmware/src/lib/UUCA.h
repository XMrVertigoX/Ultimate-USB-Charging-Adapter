/*
 * UUCA.h - Feature library for the (U)ltimate (U)SB (C)harging (A)dapter
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef LIB_UUCA_H_
#define LIB_UUCA_H_

#include <inttypes.h>

void SPI_Init(void);
void SPI_Transmit(uint8_t ss, uint8_t data);

#endif /* LIB_UUCA_H_ */
