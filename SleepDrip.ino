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


int sample_per_sec = 10;

void setup()
{
	setup_leds();
	setup_screen();	
	adc_setup();
    Serial.begin(115200);
}

/* Every loop should take 1 sec */
void loop()
{

	status_t status = STATUS_OK;
	int i = 0;
	int value = 0;
	
	/* Sample Driver */
	for (i = 0; i < sample_per_sec; i++) {
		adc_read(&value);
		append_buffer(value);
		delay(1000 / sample_per_sec)
	}
	
	status = logic_main(); 
	leds_loop(status);
	screen_loop(0, status);
}
