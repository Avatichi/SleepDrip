#include "../include/logic.h"

static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;

static SLOPE_TYPE slope_to_cc(SLOPE_TYPE slope)
{
	SLOPE_TYPE cc = 0;
	cc = slope; //* SYRINGE_SIZE / SAMPLE_RESULATION / SAMPLE_PER_SEC;
	return cc;
}


/* Set leds based on status */
/* run every blinking interval */
void convert_status_to_leds(logic_status_t logic_status, leds_status_t *led_status)
{
	switch(logic_status.status) {
		case STATUS_OK:
			led_status->should_green = !led_status->should_green;
			led_status->should_red = LOW;
			led_status->should_yellow = LOW;
			break;
		case STATUS_DETECTING:
			led_status->should_yellow = !led_status->should_yellow;
			led_status->should_red = LOW;
			led_status->should_green = LOW;
			break;
		case NO_LIQUID:
			led_status->should_yellow = !led_status->should_yellow;
			led_status->should_red = !led_status->should_red;
			led_status->should_green = !led_status->should_green;
			break;
		case STATUS_ERROR:
			led_status->should_red = HIGH;
			led_status->should_yellow = LOW;
			led_status->should_green = LOW;
			break;
		case STATUS_WARNNING:
			led_status->should_red = !led_status->should_red;
			led_status->should_yellow = LOW;
			led_status->should_green = LOW;
			break;
	}
}

	void logic_main(sampler_t *sampler, logic_status_t *logic_status)
{

	SLOPE_TYPE slope = 0;
	SLOPE_TYPE cc = 0;
	logic_status->status = STATUS_OK;

	logic_status->index++;
	if (logic_status->index < START_SAMPLE_SEC) {
		logic_status->status = STATUS_DETECTING;
		Serial.println(logic_status->index);
		return;
	}

	slope = get_slope(sampler);
	cc = slope_to_cc(slope);

	/* First sample after start, should only run once */
	if (logic_status->start_cc == 0) {
		logic_status->start_cc = cc;
		logic_status->running_cc += cc;
	}
	
	if (is_empty(sampler)) {
		logic_status->status = NO_LIQUID;
		return;
	}

	if (cc < 0.01) {
		logic_status->status = STATUS_ERROR;
		return;
	} 
	
	logic_status->running_cc = cc;
	// logic_status->running_cc /= 2;

	if ((logic_status->start_cc - logic_status->running_cc) > THRESHOLD_BAD_INJECTION) {
		logic_status->status = STATUS_WARNNING;
		return;
	} 


}
