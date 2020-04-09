#include "logic.h"


static int expected_adc_drop_sec = 14 * 1024 / 50 / 60;
static int adc_drop_counter = 0;
static int Threshold_bad_injection = 1;
static int sample_min_size = 20;


static int start_index = 0;

/* And for stop.. remeber, in stop the pressure can go back.. we need some time to get back to the game */
static status_t check_sec_potion()
{
	status_t status = STATUS_OK;
	if (start_index < sample_min_size) {
		start_index++;
	}
	else {
		int diff =  sample_array[sample_index - sample_min_size] - sample_array[sample_index - 1];
		if (diff < expected_adc_drop_sec) {
			adc_drop_counter++;
			if (adc_drop_counter > Threshold_bad_injection) {
				status = STATUS_WARNNING;
			}
		} else {
			if (status == STATUS_OK) {
				adc_drop_counter = 0;
			}
		}
	}
	return status;
}

status_t logic_main()
{
	return check_sec_potion();
}
