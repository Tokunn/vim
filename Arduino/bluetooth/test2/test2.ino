#include <SoftwareSerial.h>
#define PWM_WIDTH 500

int bt_rx = 12;
int bt_tx = 11;
int ledf = 7;

SoftwareSerial btSerial(bt_rx, bt_tx);


void setup()
{
  pinMode(ledf, OUTPUT);
  Serial.begin(9600);
  btSerial.begin(9600);
}


void loop()
{
  char com;

  if (Serial.available()){
    com = Serial.read();
  }

  if (btSerial.available()){
    com = btSerial.read();
  }

  if (com == 'f'){
    digitalWrite(ledf, HIGH);
  }

  else if (com == 'b'){
    digitalWrite(ledf, LOW);
  }
}
