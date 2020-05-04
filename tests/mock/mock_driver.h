#ifndef __MOCK_DRIVER_H__
#define __MOCK_DRIVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "config.h"
#include "driver_ops.h"

#define END_FLAG        1


void mock_setup(const void *priv);
void mock_read(DATA_TYPE *value, TIME_TYPE *timestamp);

// struct driver_ops mock_driver_ops {
//     .setup = mock_setup,
//     .read = mock_read
// };

#endif /* __MOCK_DRIVER_H__ */