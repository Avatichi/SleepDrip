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
#include "leds.h"
#include "OLED_GUI.h"


typedef struct logic_struct {
    int index;
    SLOPE_TYPE start_cc;
    SLOPE_TYPE running_cc;
    status_t status;
    status_t prv_status;
} logic_status_t;

void logic_main(sampler_t *sampler, logic_status_t *logic_status);
void convert_status_to_leds(logic_status_t *logic_status, leds_status_t *led_status);

#endif /* __LOGIC_H__ */
