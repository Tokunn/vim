byte val = 0;
int led1 = 10;
int led2 = 13;


void setup(){
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    Serial.begin(9600);
}


void loop() {
    if (Serial.available() > 0) {

        val = Serial.read();
        Serial.print(val);  //for debug

        if (val == '1') {
            digitalWrite(led1, HIGH);
            delay(1000);
        }
        else if (val == '2'){
            digitalWrite(led2, HIGH);
            delay(1000);
        }
        else if (val == '0'){
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(1000);
        }
    }
}
