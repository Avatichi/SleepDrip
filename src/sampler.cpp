#include "../include/sampler.h"


#define ARRAY_LEN   1000

/* Should change this .. */
static double sample_array[ARRAY_LEN];
static double time_array[ARRAY_LEN];

static int sample_index = -1;
static int loop_state;

static int max_back = ERROR_DETCTION_TIME * SAMPLE_PER_SEC;

void append_buffer(double value, double time)
{

	sample_index ++;
	if (sample_index >= ARRAY_LEN) {
		/* In loop state */
		sample_index = 0;
		loop_state = 1;
	}
	if (sample_index >= max_back) {
		loop_state = 0;
	}

	sample_array[sample_index] = value;
}

/* This is kind of a lie. 
 * Maybe change this in the futhre */
void get_sample_amount(int *len)
{
	if (loop_state != 1) {
		*len = sample_index;
	} else {
		*len = max_back;
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

//TODO
// Finish sampler,
// add time
double get_slope()
{
	double res1;
	double res2;
	double res3;

	// if (sample_index > ERROR_DETCTION_TIME) {
	// }

	linreg(80, time_array, sample_array, &res1, &res2, & res3);


}