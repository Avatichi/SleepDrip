int R_led = 15;
int Y_led = 5;
int G_led = 18;
int ATD = 39;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


typedef enum  {
    STATUS_OK = 0,
    STATUS_WARNNING = 1,
    STATUS_ERROR =2
} status_t;


void turn_off_all_leds()
{
    digitalWrite(G_led, LOW);
    digitalWrite(Y_led, LOW);
    digitalWrite(R_led, LOW);
}

/* This function change the led based on status
 * Green pulse - OK
 * Yellow - should refill
 * Red error
 */
int blinking_status = 0;
void blinking_leds(status_t status)
{
    turn_off_all_leds();
    blinking_status = !blinking_status;
    switch (status) {
        case STATUS_OK:
            digitalWrite(G_led, blinking_status);
            break;
        case STATUS_WARNNING:
            digitalWrite(Y_led, blinking_status);
            break;
        case STATUS_ERROR:
            digitalWrite(R_led, blinking_status);
            break;
    }
}


void setup() {
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
    analogReadResolution(12);
    pinMode(R_led, OUTPUT);
    pinMode(Y_led, OUTPUT);
    pinMode(G_led, OUTPUT);
    Serial.begin(115200);
    turn_off_all_leds();
    
    print_yehida();   
}


int THRESHOLD = 50;
int error_threshold = 50;

int current_val = 0;
int prev_val = 0;


#include <math.h>



int get_adc_value(int adc_pin)
{
    int i = 0;
    int test_len = 1000;
    int sum = 0;
    for (i = 0; i < test_len; i ++) {
        sum += analogRead(adc_pin);  
    }
    return sum / test_len;
}

status_t massure_presser()
{
    status_t result = STATUS_OK;
    current_val = analogRead(ATD);
    Serial.print("value: ");
    Serial.println(current_val);

    if (((prev_val - current_val) <= (THRESHOLD + error_threshold)) && ((prev_val - current_val) >= (THRESHOLD - error_threshold )))
    {
        result = STATUS_ERROR;
    }
    return result;
}

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

#include <driver/adc.h>
//read internal voltage
long readVcc() 
{
    //read battery voltage per %
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
    // calculate the voltage
    voltage = sum / (float)500;
    voltage = (voltage * 1.1) / 4096.0; //for internal 1.1v reference
    // use if added divider circuit
    // voltage = voltage / (R2/(R1+R2));
    //round value by two precision
    voltage = roundf(voltage * 100) / 100;
    Serial.print("voltage: ");
    Serial.println(voltage, 2);
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
  Serial.println(curvolt);
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

status_t result = STATUS_OK;
void loop() {
    // if (result != STATUS_ERROR) {    
        // result = massure_presser();
        // blinking_leds(result);
    // }
    
    int result = get_adc_value(ATD);
    lcd.setCursor(0, 2);
    lcd.print("Status  OK");

    batterylevel();

    lcd.setCursor(0, 0);
    lcd.print("Value ");
    lcd.print(result);

}