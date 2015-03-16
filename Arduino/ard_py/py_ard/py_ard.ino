byte mess = 0;

int ledf = 12;
int ledb = 11;
int ledr = 10;
int ledl = 9;


void setup(){
    pinMode(ledf, OUTPUT);
    pinMode(ledb, OUTPUT);
    pinMode(ledr, OUTPUT);
    pinMode(ledl, OUTPUT);
    Serial.begin(9600);
}


void turnupLED(int ledname, int mes){
    byte chk = 0;

    do{
        digitalWrite(ledname, HIGH);
        chk = Serial.read();
    }while (chk==mes);

    digitalWrite(ledname, LOW);
}


void loop(){
    if (Serial.available() > 0){
        mess = Serial.read();

        if (mess == 'f'){
            turnupLED(ledf, 'f');
        }
        else if (mess == 'b'){
            turnupLED(ledb, 'b');
        }
        else if (mess == 'r'){
            turnupLED(ledr, 'r');
        }
        else if (mess == 'l'){
            turnupLED(ledl, 'l');
        }

    }
}
