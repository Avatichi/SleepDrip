
#include "../include/circular_buffer.h"
#include "../include/logic.h"
#include "../include/config.h"
#include "mock/mock_driver.h"


#define FILE_PATH "../data/temp.dat"


int main()
{
    int value;
    
    mock_setup(FILE_PATH);

    while (value != -999) {
        mock_read(&value);
        printf("%d\n", value);
        printf("TEST");
    }
}