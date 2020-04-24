
#include "../include/logic.h"
#include "../include/config.h"
#include "../include/linreg.h"
#include "../include/sampler.h"

#include "mock/mock_driver.h"


#define FILE_PATH "../data/9CC_10dps.dat"

int main()
{
    double value;
    double index = 900;
    mock_setup(FILE_PATH);

    while (value != -999) {
        index += 10;
        mock_read(&value);
        // printf("sample %f\n", value);
        append_buffer((double)value, index);
        logic_main();
    }
}