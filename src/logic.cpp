#include "../include/logic.h"


static int expected_adc_drop_sec = 14 * 1024 / SYRINGE_SIZE / 60 / SAMPLE_PER_SEC;
static int drop_counter;

int _sample_len = 200;


status_t logic_main()
{
	status_t ret = STATUS_OK;
	int sample_len = 0;
	double _array[_sample_len];
	double _array_time[_sample_len];
	get_sample_amount(&sample_len);

	double res1 = 0;
	double res2 = 0;
	double res3 = 0;
	

	if (sample_len > ERROR_DETCTION_TIME) {
		for (int i = 0; i < _sample_len; i++) {
			get_item_from_end(i, &_array[i]);
			_array_time[i] = i;
		}

		linreg(_sample_len, _array, _array_time, &res1, &res2, & res3);
		printf(" %f\n", res2);
	}
	return ret;
}

