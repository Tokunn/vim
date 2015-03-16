#include <SoftwareSerial.h>


#define LED_PORT 13
#define BT_RX 11
#define BT_TX 10

#define PWM_WIDTH 500


SoftwareSerial btSerial(BT_RX, BT_TX);


int mode = 0;
int flag1 = 0;
int flag2 = 100;

void setup()
{
  pinMode(LED_PORT, OUTPUT);
  digitalWrite(LED_PORT, LOW);

  Serial.begin(9600);
  btSerial.begin(9600);
}


void loop()
{
  char c;

  if (btSerial.available()){
    c = btSerial.read();
    Serial.write(c);
  }

  if (Serial.available()){
    c = Serial.read();
    btSerial.write(c);
  }

  switch(c){
    case '0':
      Serial.write("Led = disabled\n");
      mode = 0;
      break;
    case '1':
      Serial.write("Led = enabled\n");
      mode = 1;
      break;
    case '2':
      Serial.write("Led = enabled (2)\n");
      mode =2;
  }

  switch(mode){
    case 0:
      digitalWrite(LED_PORT, LOW);
      break;
    case 1:
      digitalWrite(LED_PORT, HIGH);
      break;
  }
}
