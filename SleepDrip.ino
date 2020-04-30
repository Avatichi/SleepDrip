#include "include/leds.h"
#include "include/logic.h"
#include "include/config.h"
#include "include/sampler.h"
#include "include/error_values.h"
#include "include/screen_utils.h"

#ifdef SPI_DRIVER
	#include "include/spi_driver.h"
#else
	#include "include/adc_driver.h"
#endif

sampler_t sampler;

void setup()
{

#ifndef ONLY_SAMPLE
		setup_leds();
		setup_screen();
#endif

#ifdef SPI_DRIVER
	spi_setup();
#else
	adc_setup();
#endif

	init_sample(&sampler);
	Serial.begin(115200);
}


static int logic_index = 0;

/* Every loop should take 1 sec */
void loop()
{
	status_t status = STATUS_OK;
	int sample_index = 0;
	DATA_TYPE value = 0;
	TIME_TYPE timestamp = 0;

	DATA_TYPE sum = 0;


	for (sample_index = 0; sample_index < SAMPLE_PER_SEC; sample_index++) {

		// Read From driver
#ifdef SPI_DRIVER
		spi_read(&value);
#else
		adc_read(&value);
#endif
		// Get Read time 
		timestamp = millis();
		sum += value;
		if (DEBUG) {
			Serial.print(value);
			Serial.print(", ");
			Serial.println(timestamp);
		}

		// Store value
		append_buffer(&sampler, value, timestamp);
		delay(1000 / SAMPLE_PER_SEC);
	}
	sum /= SAMPLE_PER_SEC;
	sum = 0;

#ifndef ONLY_SAMPLE

	SLOPE_TYPE cc = 0;
	
	// status = logic_main(&sampler, &cc);

	// Serial.print("CC: ");
	// Serial.println();

 
	// leds_loop(status);
	// screen_loop(value, status);
#endif

}
