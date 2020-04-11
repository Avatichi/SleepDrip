#include "mock_driver.h"

static FILE *in_file;

void mock_setup(char *file_name)
{
	in_file = fopen(file_name, "r");
}

void mock_read(int *value)
{
	char line[6];
	if (fgets(line, 6, in_file) != NULL) {
		   sscanf(line, "%d", value);
	} else {
        *value = -999;
    }
}