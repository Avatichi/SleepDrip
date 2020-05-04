#ifndef __DRIVER_OPS_H__
#define __DRIVER_OPS_H__

#include "config.h"

typedef void (*setup_driver)(void);
typedef void (*read_driver)(DATA_TYPE *value);

struct driver_ops
{
    setup_driver setup;
    read_driver read;
};

#endif /* __DRIVER_OPS_H__ */