#define sigA 5
#define sigB 6


void setup()
{
  pinMode(sigA, OUTPUT);
  pinMode(sigB, OUTPUT);
}


void left()
{
  digitalWrite(sigA, HIGH);
  digitalWrite(sigB, LOW);
}


void right()
{
  digitalWrite(sigA, LOW);
  digitalWrite(sigB, HIGH);
}


void stop()
{
  digitalWrite(sigA, LOW);
  digitalWrite(sigB, LOW);
}


void loop()
{
}
