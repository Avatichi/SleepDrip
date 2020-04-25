#include "../include/adc_driver.h"


void adc_setup()
{
#ifdef ESP
    analogReadResolution(12);
#endif
}

void adc_read(DATA_TYPE *value)
{
    int i = 0;
    int sum = 0;
    
    /* over sample to stable the values from the ADC */
    int test_len = 1000;

    for (i = 0; i < test_len; i ++) {
        sum += analogRead(ATD);
    }
    *value = (DATA_TYPE)(sum / test_len);
}
