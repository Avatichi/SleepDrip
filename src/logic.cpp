#include "../include/logic.h"


static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;
static int drop_counter;

int _sample_len = 200;


static SLOPE_TYPE slope_to_cc(SLOPE_TYPE slope)
{
	SLOPE_TYPE cc = 0;
	cc = slope * SYRINGE_SIZE / SAMPLE_RESULATION;

	return cc;
}

status_t logic_main()
{
	status_t ret = STATUS_OK;
	SLOPE_TYPE slope = 0;
	SLOPE_TYPE cc = 0;
	
	slope = get_slope();
	cc = slope_to_cc(slope);
	// print_samples();
	if (cc < 5) {
		printf("CC %f\n", cc);

	} else {
	}
	return ret;
}

