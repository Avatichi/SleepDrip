#include "../include/logic.h"


static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;

static int drop_counter;

/* TODO: Do sample_per_sec times..  */
/* TODO: support flow error currections with more samples */
status_t logic_main()
{
	status_t ret = STATUS_OK;
	int sample_len = 0;
	int value1 = 0;
	int value2 = 0;
	int diff = 0;

	get_sample_amount(&sample_len);

	if (sample_len > ERROR_DETCTION_TIME) {
		ret = get_item_from_end(0, &value1);
		ret = get_item_from_end((sample_len - 1), &value2);
		if (ret != STATUS_OK) {
			int diff = value2 - value1;
			if (diff < expected_adc_drop_sec) {
				drop_counter++;
				if (drop_counter > THRESHOLD_BAD_INJECTION) {
					ret = STATUS_WARNNING;
				}
			} else {
				if (ret == STATUS_OK) {
					drop_counter = 0;
				}
			}
		}
	} else {
		ret = STATUS_DETECTING;
	}
	return ret;
}

