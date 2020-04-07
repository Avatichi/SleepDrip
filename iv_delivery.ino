#include <math.h>

// #include "screen_utils.h"
#include "adc_driver.h"
#include "leds.h"

int ATD = 39;

int R_led = 18;
int Y_led = 5;
int G_led = 15;


void setup()
{
	setup_leds();
	//setup_screen();	
	adc_setup();
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    int result = adc_read();
	//screen_loop(result);
}