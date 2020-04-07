#include "adc_driver.h"

int get_adc_value(int adc_pin)
{
    int i = 0;
    int test_len = 1000;
    int sum = 0;
    for (i = 0; i < test_len; i ++) {
        sum += analogRead(adc_pin);  
    }
    return sum / test_len;
}

int convert_to_cc_hour(int adc_value)
{
    return adc_value;
}


int adc_read()
{
    int value = get_adc_value(ATD);
    return convert_to_cc_hour(value);
}

void adc_setup()
{
    analogReadResolution(12);
}