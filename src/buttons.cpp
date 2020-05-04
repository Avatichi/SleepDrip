#include "../include/buttons.h"


void setup_buttons()
{
	pinMode(BUTTON_ONE, INPUT);
	pinMode(BUTTON_TWO, INPUT);
	pinMode(BUTTON_THREE, INPUT);
}

void get_button_status(leds_status_t *leds_status)
{
	leds_status->should_red = digitalRead(BUTTON_ONE);
	leds_status->should_green = digitalRead(BUTTON_THREE);
	leds_status->should_yellow = digitalRead(BUTTON_TWO);
}
