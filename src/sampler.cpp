#include "../include/sampler.h"
#include <stdio.h>
#include <string.h>

// #include "HardwareSerial.h"

void init_sample(sampler_t *sampler)
{
	memset(sampler->time_array, 0, ARRAY_LEN);
	memset(sampler->sample_array, 0, ARRAY_LEN);

	sampler->sample_index = -1;
	sampler->loop_state = 0;
}

void print_samples(sampler_t *sampler)
{
	int i = 0;
	for (i = 0; i < ARRAY_LEN; i++) {
		// Serial.print(sampler->sample_array[i]);
		// Serial.print(",");
	}

}

void append_buffer(sampler_t *sampler, DATA_TYPE value, TIME_TYPE time)
{
	sampler->sample_index++;
	if (sampler->sample_index == ARRAY_LEN) {
		/* In loop state */
		sampler->sample_index = 0;
		sampler->loop_state = 1;
	}

	sampler->sample_array[sampler->sample_index] = value;
	sampler->time_array[sampler->sample_index] = time;
}

void get_sample_amount(sampler_t *sampler, int *len)
{
	// TODO : fix this!
	if (sampler->loop_state != 1) {
		*len = sampler->sample_index;
	} else {
		*len = ARRAY_LEN;
	}
}

SLOPE_TYPE get_slope(sampler_t *sampler)
{
	SLOPE_TYPE res1;
	SLOPE_TYPE res2;
	SLOPE_TYPE res3;
	int len = 0;
	int i = 0;

	get_sample_amount(sampler, &len);
	// print_samples(sampler);
	// DATA_TYPE data_avg[7] = {0};
	// TIME_TYPE time_avg[7] = {0};
	// int index = 0;
	// for (i = 0; i < 7; i++) {
	// 	index = ARRAY_LEN / 7 * i;
	// 	data_avg[i] = sampler->sample_array[index];
	// 	time_avg[i] = sampler->time_array[index];
	// }

	// linreg(ARRAY_LEN, sampler->sample_array, sampler->time_array, &res1, &res2, &res3);
	res2 = slope(sampler->time_array,  sampler->sample_array, len);
	// Serial.print("Slope: ");
	// Serial.println(res2);
	// linreg(7, time_avg, data_avg, &res1, &res2, &res3);
	return res2;
}
