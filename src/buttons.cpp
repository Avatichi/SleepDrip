#include "../include/buttons.h"


void setup_buttons()
{
	pinMode(BUTTON_TWO, INPUT_PULLUP);
	pinMode(BUTTON_THREE, INPUT_PULLUP);
	pinMode(BUTTON_ONE, INPUT_PULLUP);
}

void get_button_status(leds_status_t *leds_status)
{
	leds_status->should_red = !digitalRead(BUTTON_ONE);
	leds_status->should_green = !digitalRead(BUTTON_THREE);
	leds_status->should_yellow = !digitalRead(BUTTON_TWO);	
}

int should_start()
{
	return !digitalRead(BUTTON_ONE);
}