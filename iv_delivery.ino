int R_led = 5;
int Y_led = 4;
int G_led = 2;
int ATD = 39;


void error()
{
    digitalWrite(R_led, HIGH);
    digitalWrite(G_led, LOW);
    digitalWrite(Y_led, LOW);
}


void setup() {
  pinMode(R_led, OUTPUT);
  pinMode(Y_led, OUTPUT);
  pinMode(G_led, OUTPUT);
  Serial.begin(115200);
  digitalWrite(R_led, LOW);
  digitalWrite(G_led, LOW);
  digitalWrite(Y_led, LOW);

}

// This number is importent!
// Should get from client 
int THRESHOLD = 50;
int error_threshold = 50;

int current_val = 0;
int prev_val = 0;
int led_state = 1;

int massure_presser()
{
    int result = 0;
    current_val = analogRead(ATD);
    Serial.print("value: ");
    Serial.println(current_val);

    if (((prev_val - current_val) <= (THRESHOLD + error_threshold)) && ((prev_val - current_val) >= (THRESHOLD - error_threshold )))
    {
        Serial.println("All OK");
        prev_val = current_val;
        
        led_state= !led_state;
        digitalWrite(G_led, led_state);
    }
    else
    {
        Serial.println("BADD");
        error();
        result = 1;
    }
    return result;
}

int result = 0;
void loop() {
    int i;
    delay(1000);
    if (!result) {
        result = massure_presser();
        delay(1000);
    }
}
