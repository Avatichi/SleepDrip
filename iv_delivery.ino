int R_led = 5;
int Y_led = 4;
int G_led = 2;
int ATD = 39;

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
    pinMode(R_led, OUTPUT);
    pinMode(Y_led, OUTPUT);
    pinMode(G_led, OUTPUT);
    Serial.begin(115200);
    turn_off_all_leds();
}


int THRESHOLD = 50;
int error_threshold = 50;

int current_val = 0;
int prev_val = 0;


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

status_t result = STATUS_OK;
void loop() {
    if (result != STATUS_ERROR) {    
        result = massure_presser();
        blinking_leds(result);
    }
    delay(1000);
}
