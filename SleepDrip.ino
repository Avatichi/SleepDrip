#include "include/leds.h"
#include "include/logic.h"
#include "include/config.h"
#include "include/adc_driver.h"
#include "include/error_values.h"
#include "include/screen_utils.h"
#include "include/circular_buffer.h"


void setup()
{
	if (!ONLY_SAMPLE) {
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

	for (i = 0; i < SAMPLE_PER_SEC; i++) {
		adc_read(&value);
		if (DEBUG) {
			Serial.println(value);
		} 
		append_buffer(value);
		delay(1000 / SAMPLE_PER_SEC);
	}
	
	if (!ONLY_SAMPLE) {
		status = logic_main();
		leds_loop(status);
		screen_loop(0, status);
	}
}
