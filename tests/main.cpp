
#include "../include/circular_buffer.h"
#include "../include/logic.h"
#include "../include/config.h"
#include "../include/linreg.h"

#include "mock/mock_driver.h"


#define FILE_PATH "../data/11CC_10dps.dat"


int main()
{
    int value;

    mock_setup(FILE_PATH);

    while (value != -999) {
        mock_read(&value);
        printf("%d\n", value);
        append_buffer((double)value);
        logic_main();
    }
}