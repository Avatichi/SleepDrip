#include "../include/sampler.h"
#include <stdio.h>

void Sampler::print_samples()
{
	int i = 0;
	for (i = 0; i < ARRAY_LEN; i++) {
		printf("%d ,", sample_array[i]);
	}
	printf("\n");

}

void Sampler::append_buffer(DATA_TYPE value, TIME_TYPE time)
{

	sample_index ++;
	if (sample_index >= ARRAY_LEN) {
		/* In loop state */
		sample_index = 0;
		loop_state = 1;
	}
	if (sample_index >= ARRAY_LEN) {
		loop_state = 0;
	}

	sample_array[sample_index] = value;
	time_array[sample_index] = time;
}

void Sampler::get_sample_amount(int *len)
{
	// TODO : fix this!
	if (loop_state != 1) {
		*len = sample_index;
	} else {
		*len = ARRAY_LEN;
	}
}

SLOPE_TYPE Sampler::get_slope()
{
	SLOPE_TYPE res1;
	SLOPE_TYPE res2;
	SLOPE_TYPE res3;
	int len = 0;

	get_sample_amount(&len);

	linreg(ARRAY_LEN, time_array, sample_array, &res1, &res2, & res3);
	return res2;

}