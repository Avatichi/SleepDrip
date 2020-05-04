#ifndef __LOGIC_H__
#define __LOGIC_H__


#ifdef TEST
#include <stdio.h>
#else
#include <Arduino.h>
#endif

#include "config.h"
#include "sampler.h"
#include "error_values.h"


typedef struct logic_struct {
    int index;
    SLOPE_TYPE running_cc;
    status_t status;
} logic_status_t;

void logic_main(sampler_t *sampler, logic_status_t *logic_status);

#endif /* __LOGIC_H__ */
