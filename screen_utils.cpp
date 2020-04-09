#include "screen_utils.h"


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

void screen_loop(int CC_value)
{    
	batterylevel();

	lcd.setCursor(0, 0);
	lcd.print("CC     ");
	lcd.setCursor(4, 0);
	lcd.print(CC_value);
}
