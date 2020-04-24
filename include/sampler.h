#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include "config.h"
#include "linreg.h"
#include "error_values.h"

// void get_sample_amount(int *len);

void append_buffer(double value, double time);
// status_t get_item_from_end(int index_from_end, double *value);
double get_slope(void);

#endif /* __SAMPLER_H__ */
