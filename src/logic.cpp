#include "../include/logic.h"


static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;
static int drop_counter;

int _sample_len = 200;


double slope_to_cc(double slope)
{
	double cc = 0;
	cc = slope * SYRINGE_SIZE / SAMPLE_RESULATION;

	return cc;
}

status_t logic_main()
{
	status_t ret = STATUS_OK;
	double slope = 0;
	double cc = 0;	
	
	slope = get_slope();
	cc = slope_to_cc(slope);
	printf("CC %f\n", cc);

	return ret;
}

