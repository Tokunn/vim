#define LED 12


void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  byte mes = 0;
  if (Serial.available() > 0){
    mes = Serial.read();

    if (mes == 'f'){
      digitalWrite(LED, HIGH);
      Serial.println("Turn up LED");
    }
    else if (mes == 'b'){
      digitalWrite(LED, LOW);
      Serial.println("Turn off LED");
    }
  }
}
