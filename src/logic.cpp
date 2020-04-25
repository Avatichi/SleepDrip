#include "../include/logic.h"

static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;

static SLOPE_TYPE slope_to_cc(SLOPE_TYPE slope)
{
	SLOPE_TYPE cc = 0;
	cc = slope * SYRINGE_SIZE / SAMPLE_RESULATION;

	return cc;
}

status_t logic_main(Sampler sampler)
{
	status_t ret = STATUS_OK;
	SLOPE_TYPE slope = 0;
	SLOPE_TYPE cc = 0;
	
	slope = sampler.get_slope();
	cc = slope_to_cc(slope);
	printf("CC %f\n", cc);
	return ret;
}

