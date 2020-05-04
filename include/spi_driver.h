#ifndef __SPI_DRIVER_H__
#define __SPI_DRIVER_H__

#include <SPI.h>
#include <Arduino.h>

#include "driver_ops.h"
#include "config.h"

void spi_setup(void);

void spi_read(DATA_TYPE *value);

static struct driver_ops spi_driver_ops {
    .setup = spi_setup,
    .read = spi_read
};

#endif /* __SPI_DRIVER_H__ */
