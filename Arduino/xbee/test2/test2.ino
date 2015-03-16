#define f = 12
#define b = 11
#define r = 10
#define l = 9


void setup()
{
  pinMode(f, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(l, OUTPUT);
  Serial.begin(9600);
}


void turnup_led(byte mes)
{
  byte chk = 0;
  digitalWrite(mes, HIGH);
  do{
    chk = Serial.read();
  }while (chk == mes);
  digitalWrite(mes, LOW);
}


void loop()
{
  if (Serial.available() > 0){
    byte mes = Serial.read();
    turnup_led(mes);
  }
}
