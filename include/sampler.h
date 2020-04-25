#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include "config.h"
#include "linreg.h"
#include "error_values.h"


class Sampler{
	DATA_TYPE sample_array[ARRAY_LEN];
	TIME_TYPE time_array[ARRAY_LEN];
    int sample_index = -1;
    int loop_state;
	
	public:
		void print_samples();
		void append_buffer(DATA_TYPE value, TIME_TYPE time);
		void get_sample_amount(int *len);
        SLOPE_TYPE get_slope();
};

#endif /* __SAMPLER_H__ */