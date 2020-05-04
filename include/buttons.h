#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "leds.h"
#include "config.h"
#include "error_values.h"

void setup_buttons();
void get_button_status(leds_status_t *leds_status);

#endif /* __BUTTONS_H__ */
