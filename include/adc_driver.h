#ifndef __ADC_DRIVER_H__
#define __ADC_DRIVER_H__

#ifdef ESP
    #include <driver/adc.h>
#endif

#include <Arduino.h>

#include "config.h"

void adc_setup();
void adc_read(int *value);

#endif /* __ADC_DRIVER_H__ */
