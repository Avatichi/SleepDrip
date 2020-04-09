#ifndef __LOGIC_H__
#define __LOGIC_H__

/* NOTE: choose between < and " for ardunio libs */
#include <Arduino.h>
// #include <HardwareSerial.h>

// extern HardwareSerial Serial;


/* For raw values */
extern int sample_array[];
extern int sample_index;
extern int sample_per_sec;


/* For cc logic */
extern int expected_injection_time;
extern int max_adc_value;


/* Call this once per second */
int logic_main();

#endif /* __LOGIC_H__ */