#include "mock_driver.h"

static FILE *in_file;

void mock_setup(const void *priv)
{
	in_file = fopen((char *)priv, "r");
}

void mock_read(DATA_TYPE *value, TIME_TYPE *timestamp)
{
	int temp_value = 0;
	int temp_time = 0;

	if(fscanf(in_file, "%d, %d\n", &temp_value, &temp_time) != EOF){
		*value = (DATA_TYPE)temp_value;
		*timestamp = (TIME_TYPE)temp_time;
	} else {
        *value = END_FLAG;
		*timestamp = END_FLAG;
    }
}
