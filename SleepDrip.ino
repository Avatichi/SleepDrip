#include "include/leds.h"
#include "include/logic.h"
#include "include/adc_driver.h"
#include "include/error_values.h"
#include "include/screen_utils.h"
#include "include/circular_buffer.h"


/* Hardware Configuration */
int ATD = 39;
int BATTERY_ADC = 36;

int R_led = 13;
int Y_led = 14;
int G_led = 12;


/* How many samples in a second to take
 * from 1 to 1000 samples per second */
int sample_per_sec = 10;

/* syringe_size in cc */
int syringe_size = 50;

/* How much error to get before indicate error to user
 * this number is the amount of time the state machine waits (in seconds)
 * until it indicated error, to stop false positives */
int Threshold_bad_injection = 3;

/* How much time in seconds takes to detect error
 * The bigger the number, the better the results will be, but it will take more time */
int error_dection_time = 20;

int debug = 1;
int only_sample = 1;

void setup()
{
	if (only_sample != 1) {
		setup_leds();
		setup_screen();
	}

	adc_setup();
    Serial.begin(115200);
}

/* Every loop should take 1 sec */
void loop()
{
	status_t status = STATUS_OK;
	int i = 0;
	int value = 0;

	for (i = 0; i < sample_per_sec; i++) {
		adc_read(&value);
		if (debug == 1) {
			Serial.println(value);
		} 
		append_buffer(value);
		delay(1000 / sample_per_sec);
	}
	
	if (only_sample != 1) {
		status = logic_main();
		leds_loop(status);
		screen_loop(0, status);
	}
}
