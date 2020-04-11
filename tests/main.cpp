
#include "../include/circular_buffer.h"
#include "../include/logic.h"
#include "mock/mock_driver.h"

/* How many samples in a second to take
 * from 1 to 1000 samples per second */
int sample_per_sec = 10;

/* syringe_size in cc */
int syringe_size = 50;

/* How much error to get before indicate error to user
 * this number is the amount of time the state machine waits (in seconds)
 * until it indicated error, to stop false positives */
int Threshold_bad_injection = 3;

/* How much time in seconds takes to detect error
 * The bigger the number, the better the results will be, but it will take more time */
int error_dection_time = 20;

int debug = 1;

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