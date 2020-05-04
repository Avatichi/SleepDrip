#ifndef __LEDS_H__
#define __LEDS_H__

#include <Arduino.h>

#include "error_values.h"
#include "config.h"

typedef struct leds_status {
    int should_red;
    int should_yellow;
    int should_green;
} leds_status_t;

static int blinking_status = 0;

void setup_leds(leds_status_t *led_status);
void turn_off_all_leds();
void leds_loop(status_t status);
void should_led(leds_status_t led_status);

#endif /* __LEDS_H__ */
