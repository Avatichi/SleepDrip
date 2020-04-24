#include "../include/sampler.h"


static double sample_array[ARRAY_LEN];
static double time_array[ARRAY_LEN];

static int sample_index = -1;
static int loop_state;

void append_buffer(double value, double time)
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

void get_sample_amount(int *len)
{
	if (loop_state != 1) {
		*len = sample_index;
	} else {
		*len = ARRAY_LEN;
	}
}

status_t get_item_from_end(int index_from_end, double *value)
{
	status_t ret = STATUS_OK;
	
	if (loop_state != 1) {
		if (sample_index < index_from_end) {
			ret = BUFFER_ERROR;
		} else {
			*value = sample_array[sample_index - index_from_end];
		}
	} else {
		if (sample_index < index_from_end) {
			sample_array[sample_index - index_from_end];
		} else {
			*value = sample_array[ARRAY_LEN - (index_from_end - sample_index)];
		}
	}
	return ret;
}


double get_slope()
{
	double res1;
	double res2;
	double res3;
	int len = 0;

	get_sample_amount(&len);

	linreg(len, time_array, sample_array, &res1, &res2, & res3);
	return res2;

}