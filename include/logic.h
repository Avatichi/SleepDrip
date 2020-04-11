#ifndef __LOGIC_H__
#define __LOGIC_H__

#ifndef TEST
#include <Arduino.h>
#endif /* TEST*/

#include "error_values.h"
#include "circular_buffer.h"
#include "config.h"

status_t logic_main();

#endif /* __LOGIC_H__ */