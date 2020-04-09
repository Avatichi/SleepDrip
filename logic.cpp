#include "logic.h"



static int check_sec_potion()
{
	/* Test for loop around */
	/* And for stop.. remeber, in stop the pressure can go back.. we need some time to get back to the game */
	int diff =  sample_array[sample_index]- sample_array[sample_index - 1];
	int expected_adc_drop = expected_injection_time * 1024 / 50 / 60;
	/* Check for stop */
	if (diff <= 0) {
		Serial.println("stop!");

	}
	else if (diff < expected_adc_drop) {
		Serial.println("bad_injection");
	}
	return expected_adc_drop;
}


/* Call this once per second */
int logic_main()
{
	/* TODO: loop around */

	return check_sec_potion();

}