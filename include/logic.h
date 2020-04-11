#ifndef __LOGIC_H__
#define __LOGIC_H__

#ifndef TEST
#include <Arduino.h>
#endif /* TEST*/

#include "error_values.h"
#include "circular_buffer.h"

/* Values from main */ 
extern int sample_per_sec;
extern int syringe_size;
extern int Threshold_bad_injection;
extern int error_dection_time;


status_t logic_main();

#endif /* __LOGIC_H__ */