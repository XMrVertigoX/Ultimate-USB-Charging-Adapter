/*
 * SPI.h - SPI controller library for the UUCA
 *
 * Created on: Mar 27, 2015
 * Author: Caspar Friedrich
 */

#ifndef SPI_H_
#define SPI_H_

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>

#define MOSI PB3
#define SCK  PB5

#define POTI0 PB1
#define POTI1 PB2

typedef struct spiQueue spiQueue;
typedef struct spiRequest spiRequest;

struct spiQueue {
	uint8_t size;
	spiRequest *first, *last;
};

struct spiRequest {
	uint8_t data, pin;
	spiRequest *next, *previous;
};

/*
 * Initializes all SPI related hardware.
 */
void spi_Init(void);

/*
 * Returns true if the SPI bus ready
 */
bool spi_IsReady(void);

/*
 * Initializes the SPI queue
 */
void spiQueue_Init(spiQueue *queue);

/*
 * Adds a transfer request to the queue.
 */
void spiQueue_Queue(spiQueue *queue, spiRequest *request);

/*
 * Tranfers the next data byte in line. Should be called repeatedly.
 */
void spiQueue_TransferNext(spiQueue *queue);

void spiRequest_Init(spiRequest *request, uint8_t data, uint8_t pin);

#endif /* SPI_H_ */
