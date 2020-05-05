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

#include "include/OLED_Driver.h"
#include "include/OLED_GUI.h"
#include "include/DEV_Config.h"
#include "include/Debug.h"


sampler_t sampler;
leds_status_t led_status;
logic_status_t logic_status;

void setup()
{
	System_Init();

	OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;
	OLED_Init( OLED_ScanDir );

	OLED_ClearScreen(OLED_BACKGROUND);
	GUI_DisString_EN(START_OFFSET, 8, "SLEEP", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
	GUI_DisString_EN(START_OFFSET, 28, "DRIP", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
  	GUI_DisString_EN(START_OFFSET, FIRST_INFO_LINE, "PRESS", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
  	GUI_DisString_EN(START_OFFSET, SECOND_INFO_LINE, "BUTTON", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);


	setup_buttons();
	setup_leds(&led_status);

	// setup_screen();

#ifdef SPI_DRIVER
	spi_setup();
#else
	adc_setup();
#endif

	init_sample(&sampler);
	Serial.begin(BAUDRATE_DEBUG);
}

void main_loop_iteration()
{
	int sample_index = 0;

	DATA_TYPE value = 0;
	TIME_TYPE timestamp = 0;

	for (sample_index = 0; sample_index < SAMPLE_PER_SEC; sample_index++) {

#ifdef SPI_DRIVER
		spi_read(&value);
#else
		adc_read(&value);
#endif
		timestamp = millis();

#ifdef DEBUG
		// Serial.println(value);
		// Serial.print(", ");
		// Serial.println(timestamp);
#endif
		append_buffer(&sampler, value, timestamp);
		delay(1000 / SAMPLE_PER_SEC);
	}

	logic_main(&sampler, &logic_status);

#ifdef DEBUG
	Serial.print("CC: ");
	Serial.println(logic_status.running_cc);
#endif

	// get_button_status(&led_status);
	convert_status_to_leds(&logic_status, &led_status);
	should_led(led_status);

	// screen_loop(value, status);
}

void loop()
{
	int j;
  
	if (should_start()) {
		for (j = 0; j < 16; j ++) {
			OLED_ClearLine(0, FIRST_INFO_LINE + j);
		}
		for (j = 0; j < 16; j ++) {
			OLED_ClearLine(0, SECOND_INFO_LINE + j);
		}
		while (1) {

			main_loop_iteration();
		}
	}
}
