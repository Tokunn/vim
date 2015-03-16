#define sig_a 12
#define sig_b 11


void setup()
{
  pinMode(sig_a, OUTPUT);
  pinMode(sig_b, OUTPUT);
  Serial.begin(9600);
}


void turn(byte mes, byte a_com, byte b_com)
{
  digitalWrite(sig_a, a_com);
  digitalWrite(sig_b, b_com); 

  byte chk = 0;
  do{
    chk = Serial.read();
  }while (chk == mes);

  digitalWrite(sig_a, LOW);
  digitalWrite(sig_b, LOW);
}


void loop()
{
  if (Serial.available()){

    byte com = Serial.read();

    if (com == '
