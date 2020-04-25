#include "mock_driver.h"
#include <inttypes.h>

static FILE *in_file;

void mock_setup(char *file_name)
{
	in_file = fopen(file_name, "r");
}

void mock_read(DATA_TYPE *value)
{
	char line[10];
	int temp_value = 0;
	 *value = 0;
	if (fgets(line, 10, in_file) != NULL) {
		   sscanf(line, "%d", &temp_value);
		   *value = (DATA_TYPE)temp_value;
	} else {
        *value = SAMPLE_RESULATION;
    }
}
