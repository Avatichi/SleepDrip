#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include "config.h"
#include "linreg.h"
#include "error_values.h"

typedef struct sampler {
	DATA_TYPE sample_array[ARRAY_LEN];
	TIME_TYPE time_array[ARRAY_LEN];
    int sample_index;
    int loop_state;
} sampler_t;

int is_empty(sampler_t *sampler);
void init_sample(sampler_t *sampler);
void print_samples(sampler_t *sampler);
void append_buffer(sampler_t *sampler, DATA_TYPE value, TIME_TYPE time);
void get_sample_amount(sampler_t *sampler, int *len);
SLOPE_TYPE get_slope(sampler_t *sampler);

#endif /* __SAMPLER_H__ */
