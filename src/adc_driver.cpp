#include "../include/adc_driver.h"


void adc_setup()
{
#ifdef ESP
    analogReadResolution(12);
#endif
}

void adc_read(DATA_TYPE *value)
{
    *value = analogRead(ATD);
}
