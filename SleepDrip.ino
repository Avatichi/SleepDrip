#include "screen_utils.h"
#include "adc_driver.h"
#include "leds.h"
#include "logic.h"
#include "error_values.h"

int ATD = 39;
int BATTERY_ADC = 36;

int R_led = 13;
int Y_led = 14;
int G_led = 12;


/* For raw values */
int sample_array[1000] = {0};
int sample_index = 0;
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
	adc_read();

	Serial.print("Sample ");
	Serial.println(sample_array[sample_index - 1]); 
	blinking_leds(logic_main());
	screen_loop(cc_value);
}