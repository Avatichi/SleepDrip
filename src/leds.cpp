#include "../include/leds.h"


void turn_off_all_leds()
{
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(R_LED, LOW);
}

void setup_leds(leds_status_t* led_status)
{
	led_status->should_green = LOW;
	led_status->should_yellow = LOW;
	led_status->should_red = LOW;

    pinMode(R_LED, OUTPUT);
    pinMode(Y_LED, OUTPUT);
    pinMode(G_LED, OUTPUT);
    turn_off_all_leds();
}


void should_led(leds_status_t led_status)
{
    digitalWrite(R_LED, led_status.should_red);
    digitalWrite(G_LED, led_status.should_green);
    digitalWrite(Y_LED, led_status.should_yellow);
}
/*
 * This function change the led based on status
 * Green  - OK
 * Yellow - should refill
 * Red    - error
 */
void leds_loop(status_t status)
{
    turn_off_all_leds();
    blinking_status = !blinking_status;
    switch (status) {
        case STATUS_OK:
            digitalWrite(G_LED, blinking_status);
            break;
        case STATUS_WARNNING:
            digitalWrite(Y_LED, blinking_status);
            break;
        case STATUS_ERROR:
            digitalWrite(R_LED, blinking_status);
            break;
    }
}
