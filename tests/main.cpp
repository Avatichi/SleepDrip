
#include "../include/logic.h"
#include "../include/config.h"
#include "../include/linreg.h"
#include "../include/sampler.h"

#include "mock/mock_driver.h"


int main()
{
	DATA_TYPE sample_array[ARRAY_LEN] = {0};
	TIME_TYPE timestamp_array[ARRAY_LEN] = {0};
	
	
	DATA_TYPE value;
	TIME_TYPE timestamp;
	SLOPE_TYPE cc = 0;
	mock_setup();
	sampler_t sampler;
	init_sample(&sampler);

	while (value != END_FLAG) {
		mock_read(&value, &timestamp);

		// printf("%d, %d\n", value, timestamp);
		append_buffer(&sampler, value, timestamp);
		logic_main(&sampler, &cc);
		printf("CC: %f\n", cc);
	}
}