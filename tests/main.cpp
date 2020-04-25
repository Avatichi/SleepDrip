
#include "../include/logic.h"
#include "../include/config.h"
#include "../include/linreg.h"
#include "../include/sampler.h"

#include "mock/mock_driver.h"


#define FILE_PATH "../data/5CC_10dps.dat"

int main()
{
    DATA_TYPE value;
    TIME_TYPE index = 900;
    mock_setup(FILE_PATH);

    while (value != -999) {
        index += 1;
        mock_read(&value);
        // printf("sample %f\n", value);
        printf("index %d\n", index);
        append_buffer(value, index);
        logic_main();
    }
}