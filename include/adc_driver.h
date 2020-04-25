#ifndef __ADC_DRIVER_H__
#define __ADC_DRIVER_H__

#ifdef ESP
    #include <driver/adc.h>
#endif

#include <Arduino.h>

#include "driver_ops.h"
#include "config.h"

void adc_setup(void);
void adc_read(DATA_TYPE *value);


struct driver_ops adc_driver_ops {
    .setup = adc_setup,
    .read = adc_read
};

#endif /* __ADC_DRIVER_H__ */
