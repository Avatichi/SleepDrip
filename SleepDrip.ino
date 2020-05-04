#include "include/leds.h"
#include "include/logic.h"
#include "include/config.h"
#include "include/buttons.h"
#include "include/sampler.h"
#include "include/error_values.h"
#include "include/screen_utils.h"

#ifdef SPI_DRIVER
	#include "include/spi_driver.h"
#else
	#include "include/adc_driver.h"
#endif

sampler_t sampler;
leds_status_t led_status;

void setup()
{	
	setup_buttons();
	setup_leds(&led_status);

	setup_screen();

#ifdef SPI_DRIVER
	spi_setup();
#else
	adc_setup();
#endif

	init_sample(&sampler);
	Serial.begin(BAUDRATE_DEBUG);
}


void loop()
{
	status_t status = STATUS_OK;
	int sample_index = 0;

	SLOPE_TYPE cc = 0;
	DATA_TYPE value = 0;
	TIME_TYPE timestamp = 0;

	for (sample_index = 0; sample_index < SAMPLE_PER_SEC; sample_index++) {

		// Read From driver
#ifdef SPI_DRIVER
		spi_read(&value);
#else
		adc_read(&value);
#endif

		// Get Read time
		timestamp = millis();

#ifdef DEBUG
		// Serial.print(value);
		// Serial.print(", ");
		// Serial.println(timestamp);
#endif
		// Store value
		append_buffer(&sampler, value, timestamp);
		delay(1000 / SAMPLE_PER_SEC);
	}

	status = logic_main(&sampler, &cc);

#ifdef DEBUG
	Serial.print("CC: ");
	Serial.println(cc);
#endif

	get_button_status(&led_status);

	should_led(led_status);

	screen_loop(value, status);
}
