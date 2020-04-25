#ifndef __MOCK_DRIVER_H__
#define __MOCK_DRIVER_H__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

void mock_setup(char *file_name);
void mock_read(DATA_TYPE *value);

#endif /* __MOCK_DRIVER_H__ */