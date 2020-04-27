#ifndef __MOCK_DRIVER_H__
#define __MOCK_DRIVER_H__

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "driver_ops.h"

void mock_setup();
void mock_read(DATA_TYPE *value, TIME_TYPE *timestamp);

// struct driver_ops mock_driver_ops {
//     .setup = mock_setup,
//     .read = mock_read
// };

#define END_FLAG        1
#endif /* __MOCK_DRIVER_H__ */