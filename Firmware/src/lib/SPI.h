/*
 * SPI.h - SPI controller library for the UUCA
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef SPI_H_
#define SPI_H_

#include <inttypes.h>

void spiInit(void);
void spiTransmit(uint8_t data);

#endif /* SPI_H_ */
