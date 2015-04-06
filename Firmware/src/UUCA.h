/*
 * UUCA.h - Feature library for the (U)ltimate (U)SB (C)harging (A)dapter
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef LIB_UUCA_H_
#define LIB_UUCA_H_

#include <inttypes.h>

#include "lib/ADC.h"
#include "lib/MCP4151.h"
#include "lib/SPI.h"

#define POTI0 PB1
#define POTI1 PB2

void init(void);

void decrease(uint8_t poti);
void increase(uint8_t poti);

#endif /* LIB_UUCA_H_ */
