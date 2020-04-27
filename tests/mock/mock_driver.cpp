#include "mock_driver.h"
#include <inttypes.h>

#define FILE_PATH "../data/15cc_1_27_4_20.txt"
static FILE *in_file;

void mock_setup()
{
	in_file = fopen(FILE_PATH, "r");
}

void mock_read(DATA_TYPE *value, TIME_TYPE *timestamp)
{
	// char line[10];
	int temp_value = 0;
	int temp_time = 0;

	if(fscanf(in_file, "%d, %d\n", &temp_value, &temp_time) != EOF){
	// if (fgets(line, 10, in_file) != NULL) {
	// 	   sscanf(line, "%d", &temp_value);
	// 	   sscanf(line, "%d", &temp_time);
		*value = (DATA_TYPE)temp_value;
		*timestamp = (TIME_TYPE)temp_time;
	} else {
        *value = END_FLAG;
		*timestamp = END_FLAG;
    }
}
