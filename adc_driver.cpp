#include "adc_driver.h"


static int get_adc_value(int adc_pin)
{
    /* This should take 1 sec */ 
    int i = 0;
    int j = 0;
    int test_len = 1000;
    int test_len2 = 100;
    int sum = 0;

    for (i = 0; i < test_len2; i ++) {
        for (j = 0; j < test_len; j++) {
            sum += analogRead(adc_pin); 
        }
        delay(10);
    }
    return sum / (test_len * test_len2);
}

void adc_read()
{
    sample_array[sample_index] = get_adc_value(ATD);
    sample_index ++;
}

void adc_setup()
{
    analogReadResolution(12);
}