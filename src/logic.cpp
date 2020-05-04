#include "../include/logic.h"

static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;

static SLOPE_TYPE slope_to_cc(SLOPE_TYPE slope)
{
	SLOPE_TYPE cc = 0;
	cc = slope; //* SYRINGE_SIZE / SAMPLE_RESULATION / SAMPLE_PER_SEC;
	return cc;
}




void logic_main(sampler_t *sampler,logic_status_t *logic_status)
{
	status_t ret = STATUS_OK;
	SLOPE_TYPE slope = 0;

	logic_status->index++;

	if (logic_status->index < START_SAMPLE) {
		logic_status->status = STATUS_DETECTING;
		return;
	}
	
	slope = get_slope(sampler);

	if (logic_status->running_cc == 0){
		logic_status->running_cc += slope_to_cc(slope);		
	}
	
	logic_status->running_cc += slope_to_cc(slope);
	logic_status->running_cc /= 2;

}
