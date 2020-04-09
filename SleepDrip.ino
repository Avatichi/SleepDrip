#include "screen_utils.h"
#include "adc_driver.h"
#include "leds.h"
#include "logic.h"
#include "error_values.h"

int ATD = 39;
int BATTERY_ADC = 36;

int atd2 = 38;
int sw_1 = 19;
int sw_2 = 23;

int R_led = 13;
int Y_led = 14;
int G_led = 12;


/* For raw values */
int sample_array[1000] = {0};
int sample_index = 0;
int sample_per_sec = 100;

/* For cc logic */
int expected_injection_time = 5; // in CC / min
int max_adc_value = 4096; // can change


void setup()
{
	setup_leds();
	setup_screen();	
	adc_setup();
    Serial.begin(115200);
}

void loop()
{
	adc_read();
	/* For debug only */
	Serial.print("Sample ");
	Serial.println(sample_array[sample_index - 1]); 
	blinking_leds(logic_main());
	screen_loop(50);
}