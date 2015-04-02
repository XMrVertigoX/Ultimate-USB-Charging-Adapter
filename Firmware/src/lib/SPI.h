/*
 * SPI.h
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef LIB_SPI_H_
#define LIB_SPI_H_

#include <inttypes.h>

void SPI_Init();
void SPI_AddSlave(uint8_t ss);
void SPI_Transmit(uint8_t ss, uint8_t *data, uint8_t quantity);

#endif /* LIB_SPI_H_ */
