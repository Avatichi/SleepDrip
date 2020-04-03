int R_led = 5;
int Y_led = 4;
int G_led = 2;
int ATD = 39;



#define NUM_DES_LEN 9
int num_pins[NUM_DES_LEN] = {13, 12, 14, 27, 26, 25, 35, 34};
int case_1[NUM_DES_LEN] = {LOW, LOW,LOW,HIGH,LOW,LOW, LOW};
int case_2[NUM_DES_LEN] = {HIGH,HIGH,LOW,HIGH,LOW,HIGH, LOW};


void write_num(int num)
{
    int * reqest_value ;
    switch (num)
    {
    case 1:
        reqest_value = case_1;
        break;
    case2:
        reqest_value = case_2;
        break;
    default:
        break;
    }
    int i;
    for (i = 0; i < NUM_DES_LEN; i++) {
        digitalWrite(num_pins[i], HIGH);
    }

}


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

    int i;
    for (i = 0; i< NUM_DES_LEN ; i++) {
        pinMode(num_pins[i], OUTPUT);
    }

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
    for (i = 0; i < NUM_DES_LEN; i++) {
        digitalWrite(num_pins[i], LOW);
    }
    delay(1000);
    write_num(3);
    if (!result) {
        result = massure_presser();
        delay(1000);
    }
}
