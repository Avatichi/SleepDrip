#include "../include/screen_utils.h"


LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void batterylevel()
{
	int i;
	float vbat = (127.0f/100.0f) * 3.30f * float(analogRead(BATTERY_ADC)) / 4095.0f;
	int bars = (4.2 - vbat) / 0.3;

	lcd.setCursor(1, 3);
	lcd.print("[");
	for (i = 3; i >= 0; i--) {
		if (i < bars) {
			lcd.print(" ");
		} else {
			lcd.print("-");
		}
	}
	lcd.print("]");
}

void print_yehida()
{
	lcd.setCursor(16, 0);
	lcd.print("'");
	lcd.setCursor(13, 1);
	lcd.print("O O O O");
	lcd.setCursor(14, 2);
	lcd.print("O O O");
	lcd.setCursor(15, 3);
	lcd.print("O O");
}

void setup_screen()
{
	lcd.init();
	lcd.backlight();
	print_yehida();
}

void print_status(status_t status)
{
	lcd.setCursor(0, 0);
	switch (status) {
		case STATUS_OK:
			lcd.print("OK     ");
			break;
		case STATUS_WARNNING:
			lcd.print("Warning");
			break;
		case STATUS_ERROR:
			lcd.print("Error  ");
			break;
	}
}

void screen_loop(int CC_value, status_t status)
{
	batterylevel();
	print_status(status);
	lcd.setCursor(0, 1);
	lcd.print("     ");
	lcd.setCursor(0, 1);
	lcd.print(CC_value);
}
