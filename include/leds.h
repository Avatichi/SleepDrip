#ifndef __LEDS_H__
#define __LEDS_H__

#include <Arduino.h>

#include "error_values.h"


extern int R_led;
extern int Y_led;
extern int G_led;

static int blinking_status = 0;

void setup_leds();
void turn_off_all_leds();
void leds_loop(status_t status);

#endif /* __LEDS_H__ */
