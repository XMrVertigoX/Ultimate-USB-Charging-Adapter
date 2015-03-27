/*
 * SPI.h
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 *
 * Inspired by http://www.embedds.com/serial-peripheral-interface-in-avr-microcontrollers/
 */

#ifndef SPI_H_
#define SPI_H_

#include <inttypes.h>

void SPIMasterInit(void);
void SPIMasterSend(uint8_t data);

#endif /* SPI_H_ */
