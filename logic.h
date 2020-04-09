#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <Arduino.h>

#include "error_values.h"


/* For raw values */
extern int sample_array[];
extern int sample_index;
extern int sample_per_sec;

/* For cc logic */
extern int expected_injection_time;
extern int max_adc_value;


/* Call this once per second */
status_t logic_main(int *cc_flow);

#endif /* __LOGIC_H__ */