/*
 * SPI.h
 *
 * Created on: 26.03.2015
 * Author: Caspar Friedrich
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LIB_SPI_H_
#define LIB_SPI_H_

#include <inttypes.h>

void SPI_MasterInit(void);
void SPI_MasterTransmit(uint8_t data);

#endif /* LIB_SPI_H_ */

#ifdef __cplusplus
}
#endif
