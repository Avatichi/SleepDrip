#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <Arduino.h>

#include "error_values.h"
#include "circular_buffer.h"

/* Values from main */ 
extern int sample_per_sec;
extern int syringe_size;
extern int Threshold_bad_injection;
extern int error_dection_time;


status_t logic_main();

#endif /* __LOGIC_H__ */