#ifndef __ADC_DRIVER_H__
#define __ADC_DRIVER_H__

#include <driver/adc.h>
#include <Arduino.h>


extern int ATD;

extern int sample_array[];
extern int sample_index;
extern int sample_per_sec;

void adc_read();
void adc_setup();

#endif /* __ADC_DRIVER_H__ */
