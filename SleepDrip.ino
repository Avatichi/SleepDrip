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

	Serial.begin(115200);
}

/* Every loop should take 1 sec */
void loop()
{
	status_t status = STATUS_OK;
	int i = 0;
	DATA_TYPE value = 0;
	TIME_TYPE timestamp = 0;

	for (i = 0; i < SAMPLE_PER_SEC; i++) {

		// Read From driver
#ifdef SPI_DRIVER
		spi_read(&value);
#else
		adc_read(&value);
#endif
		if (DEBUG) {
			Serial.println(value);
		}

		// Get Read time 
		// timestamp = get_time();
		timestamp = 1;
		// Store value
		append_buffer(value, timestamp);
		delay(1000 / SAMPLE_PER_SEC);
	}

#ifndef ONLY_SAMPLE
	status = logic_main();
	leds_loop(status);
	screen_loop(0, status);
#endif

}
