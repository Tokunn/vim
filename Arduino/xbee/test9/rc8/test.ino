int signal = 8;
int led1 = 7;
int led2 = 6;
boolean flag = 0;


void setup()
{
    pinMode(signal, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    Serial.begin(9600);
}


void turnup(int led_name)
{
    if (led_name == 1){
        digitalWrite(led1, HIGH);
        delay(2000);
        digitalWrite(led1, LOW);
        flag = 1;
    }
    
    else if(led_name == 2){
        digitalWrite(led2, HIGH);
        delay(2000);
        digitalWrite(led2, LOW);
        flag = 0;
    }
}


void loop()
{
    boolean signal_temp = digitalRead(signal);

    if(signal_temp) {
        if(flag == 1) {
            turnup(2);
        }
        else if(flag == 0) {
            turnup(1);
        }
