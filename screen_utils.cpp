#include "screen_utils.h"


LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

/* 
long readVcc()
{
    long sum = 0;                  // sum of samples taken
    float voltage = 0.0;           // calculated voltage
    float output = 0.0;            //output value
    const float battery_max = 3.6; //maximum voltage of battery
    const float battery_min = 3.3; //minimum voltage of battery before shutdown

    float R1 = 100000.0; // resistance of R1 (100K)
    float R2 = 10000.0;  // resistance of R2 (10K)

    for (int i = 0; i < 500; i++)
    {
        sum += adc1_get_voltage(ADC1_CHANNEL_0);
        delayMicroseconds(1000);
    }
    voltage = sum / (float)500;
    voltage = (voltage * 1.1) / 4096.0; //for internal 1.1v reference
    voltage = roundf(voltage * 100) / 100;
    // Serial.print("voltage: ");
    // Serial.println(voltage, 2);
    output = ((voltage - battery_min) / (battery_max - battery_min)) * 100;
    if (output < 100)
        return output;
    else
        return 100.0f;
}

void batterylevel()
{
    lcd.setCursor(1, 3);

  //read the voltage and convert it to volt
  double curvolt = double( readVcc() ) / 1000;
//   Serial.println(curvolt);
  // check if voltge is bigger than 4.2 volt so this is a power source
  if(curvolt > 4.2)
  {
    lcd.print("[=======]");
  }
  if(curvolt <= 4.2 && curvolt > 4.0)
  {
    lcd.print("[====== ]");
  }
  if(curvolt <= 4.0 && curvolt > 3.8)
  {
    lcd.print("[=====  ]");
  }
  if(curvolt <= 3.8 && curvolt > 3.6)
  {
    lcd.print("[====   ]");
  }
  if(curvolt <= 3.6 && curvolt > 3.4)
  {
    lcd.print("[===    ]");
  }
  if(curvolt <= 3.4 && curvolt > 3.2)
  {
    lcd.print("[==     ]");
  }
  if(curvolt <= 3.2 && curvolt > 3.0)
  {
    lcd.print("[=      ]");
  }
  if(curvolt < 3.0)
  {
    lcd.print("[       ]");
  }
}

*/

void print_yehida()
{
    lcd.setCursor(13, 0);
    lcd.print("   '");
    lcd.setCursor(13, 1);
    lcd.print("O O O O");
    lcd.setCursor(13, 2);
    lcd.print(" O O O");
    lcd.setCursor(13, 3);
    lcd.print("  O O");
}

void setup_screen()
{
    lcd.init();
	lcd.backlight();
    print_yehida();   

}

void screen_loop(int inzector_value)
{
    // if (inzector_value <= 50) {
    //     lcd.setCursor(0, 2);
    //     lcd.print("Status  BAD");
    //     blinking_leds(STATUS_ERROR);
    // }
    // else if (inzector_value <= 100 ) {
    //     lcd.setCursor(0, 2);
    //     lcd.print("Status  BAD");
    //     blinking_leds(STATUS_WARNNING);
        
    // }
    // else {
    //     lcd.setCursor(0, 2);
    //     lcd.print("Status  OK ");
    //     blinking_leds(STATUS_OK);
        
    // }
    
    // batterylevel();

    lcd.setCursor(0, 0);
    lcd.print("Value     ");
    lcd.setCursor(6, 0);
    lcd.print(inzector_value);
}