#ifndef __LEDS_H__
#define __LEDS_H__

#include <Arduino.h>


extern int R_led;
extern int Y_led;
extern int G_led;

typedef enum  {
    STATUS_OK = 0,
    STATUS_WARNNING = 1,
    STATUS_ERROR =2
} status_t;

static int blinking_status = 0;

void setup_leds();
void turn_off_all_leds();
void blinking_leds(status_t status);

#endif /* __LEDS_H__ */
