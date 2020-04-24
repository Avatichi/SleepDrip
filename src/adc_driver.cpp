#include "../include/adc_driver.h"


void adc_setup()
{
#ifdef ESP
    analogReadResolution(12);
#endif
}

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

void adc_read(double *value)
{
    get_adc_value(ATD, value);
}
