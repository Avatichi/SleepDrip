#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include "error_values.h"
#include "config.h"


// void get_sample_amount(int *len);

void append_buffer(double value, double time);
// status_t get_item_from_end(int index_from_end, double *value);
double get_slope();

#endif /* __SAMPLER_H__ */