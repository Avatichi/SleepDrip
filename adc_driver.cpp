#include "adc_driver.h"


void get_adc_value(int adc_pin, int *value)
{
    int i = 0;
    int sum = 0;
    
    /* over sample to stable the values from the ADC */
    int test_len = 1000;

    for (i = 0; i < test_len; i ++) {
        sum += analogRead(adc_pin);
    }
    *value = (sum / test_len);
}

void adc_read(int *value)
{
    get_adc_value(ATD, value);
}

void adc_setup()
{
    analogReadResolution(12);
}