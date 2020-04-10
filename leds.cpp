#include "include/leds.h"


void turn_off_all_leds()
{
    digitalWrite(G_led, LOW);
    digitalWrite(Y_led, LOW);
    digitalWrite(R_led, LOW);
}

void setup_leds()
{
    pinMode(R_led, OUTPUT);
    pinMode(Y_led, OUTPUT);
    pinMode(G_led, OUTPUT);
    turn_off_all_leds();
}

/* This function change the led based on status
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
            digitalWrite(G_led, blinking_status);
            break;
        case STATUS_WARNNING:
            digitalWrite(Y_led, blinking_status);
            break;
        case STATUS_ERROR:
            digitalWrite(R_led, blinking_status);
            break;
    }
}
