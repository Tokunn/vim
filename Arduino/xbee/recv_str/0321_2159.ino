#define led 12


void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void recv_str(char *buf)
{
  int i = 0;
  char c;
  while (1) {
    if (Serial.available()) {
      c = Serial.read();
      buf[i] = c;
      if (c == '\0') break;
      i++;
    }
  }
  buf[i] = '\0';
}


void loop()
{
  char str[20];
  recv_str(str);
  if (str[0] == 'a'){
    digitalWrite(led, HIGH);
  }
  if (str[1] == 'b'){
    digitalWrite(led, LOW);
  }
}
