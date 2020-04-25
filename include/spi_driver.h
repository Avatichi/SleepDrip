#ifndef __SPI_DRIVER_H__
#define __SPI_DRIVER_H__

#include <SPI.h>
#include <Arduino.h>

#include "config.h"

void spi_setup(void);
void spi_read(DATA_TYPE *value);

#endif /* __SPI_DRIVER_H__ */
