/*
 * UUCA.h - Feature library for the (U)ltimate (U)SB (C)harging (A)dapter
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef LIB_UUCA_H_
#define LIB_UUCA_H_

#include <inttypes.h>
#include <stdbool.h>

#include "MCP4151.h"

// Input functions
uint16_t input_read(uint8_t device);

// Output functions
uint16_t output_read(uint8_t device);

#endif /* LIB_UUCA_H_ */
