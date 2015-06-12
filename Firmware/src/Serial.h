/*
 * Serial.h
 *
 * Created on: May 13, 2015
 * Author: Caspar Friedrich
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>
#include <avr/io.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU/(USART_BAUDRATE*16UL)) - 1)

void Serial_init(void);
void Serial_print(uint8_t string[]);
void Serial_printNumeric(uint8_t value, uint8_t base);
void Serial_write(uint8_t data);

#endif /* SERIAL_H_ */
