
#include "../include/logic.h"
#include "../include/config.h"
#include "../include/linreg.h"
#include "../include/sampler.h"

#include "mock/mock_driver.h"


#define FILE_PATH "../data/9CC_10dps.dat"

int main()
{
	DATA_TYPE value;
	TIME_TYPE index = 900;
	mock_setup(FILE_PATH);
	Sampler sampler;
	while (value != SAMPLE_RESULATION) {
		index += 1;
		mock_read(&value);

		sampler.append_buffer(value, index);
		logic_main(sampler);
	}
}