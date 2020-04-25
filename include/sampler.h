#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include "config.h"
#include "linreg.h"
#include "error_values.h"

// void get_sample_amount(int *len);

void append_buffer(DATA_TYPE value, TIME_TYPE time);

SLOPE_TYPE get_slope();

void print_samples();

#endif /* __SAMPLER_H__ */