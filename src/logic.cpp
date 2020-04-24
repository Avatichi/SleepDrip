#include "../include/logic.h"


static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;
static int drop_counter;

int _sample_len = 200;


status_t logic_main()
{
	status_t ret = STATUS_OK;
	int sample_len = 0;
	
	double slope = 0;
	slope = get_slope();
	printf(" %f\n", slope);

	return ret;
}

