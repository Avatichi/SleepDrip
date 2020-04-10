#include "screen_utils.h"
#include "adc_driver.h"
#include "leds.h"
#include "logic.h"
#include "error_values.h"
#include "circular_buffer.h"


int ATD = 39;
int BATTERY_ADC = 36;

int R_led = 13;
int Y_led = 14;
int G_led = 12;


int sample_per_sec = 100;

void setup()
{
	setup_leds();
	setup_screen();	
	adc_setup();
    Serial.begin(115200);
}

void loop()
{
	int cc_value = 0;
	status_t status = STATUS_OK;
	adc_read();
	
	status = logic_main(&cc_value); 
	leds_loop(status);
	screen_loop(cc_value, status);
}
