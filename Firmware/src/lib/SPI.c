#include "SPI.h"

/*
 * SPI.c
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

// ----- SPI Functions ---------------------------------------------------------

void spi_Init(void) {
	// Set MOSI and SCK as outputs
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << POTI0) | (1 << POTI1);

	// Enable master SPI at clock rate Fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

	// Set both SS lines high
	PORTB |= (1 << POTI0) | (1 << POTI1);
}

bool spi_IsReady(void) {
	bool tmp = SPSR & (1 << SPIF);

	return tmp;
}

// ----- Queue Functions -------------------------------------------------------

void spiQueue_Init(spiQueue *self) {
	self->size = 0;
	self->first = 0;
	self->last = 0;
}

void spiQueue_Queue(spiQueue *self, spiRequest *request) {
	if (self->size == 0) {
		self->first = request;
		self->last = request;
		self->size = 1;
	} else if (self->size == 255) {
		// Drop request if queue is full
	} else {
		request->next = self->first;
		self->first = request;
		self->size++;
	}
}

void spiQueue_TransferNext(spiQueue *self) {
	PORTB &= ~(1 << self->first->pin); // SS pin low

	SPDR = self->first->data; // Send data byte

	PORTB |= (1 << self->first->pin); // SS pin high

	// TODO: Pop the request from the list
}

// ----- Request Functions -----------------------------------------------------

void spiRequest_Init(spiRequest *self, uint8_t data, uint8_t pin) {
	self->data = data;
	self->pin = pin;
	self->next = 0;
	self->previous = 0;
}
