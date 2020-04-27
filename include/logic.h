#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <stdio.h>
// #include <Arduino.h>

#include "config.h"
#include "sampler.h"
#include "error_values.h"

status_t logic_main(sampler_t *sampler, SLOPE_TYPE *cc);

#endif /* __LOGIC_H__ */