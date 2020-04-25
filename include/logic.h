#ifndef __LOGIC_H__
#define __LOGIC_H__

#ifdef TEST
    #include <stdio.h>
#else
    #include <Arduino.h>
#endif /* TEST*/

#include "config.h"
#include "sampler.h"
#include "error_values.h"

status_t logic_main(Sampler sampler);

#endif /* __LOGIC_H__ */