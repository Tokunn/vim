#include <SoftwareSerial.h>

#define PWM_WIDTH 500


int ledf = 13;
int ledb = 8;
int leds = 7;
int bt_rx = 11;
int bt_tx = 10;

int mode = 0;
int flag1 = 0;
int flag2 = 100;


SoftwareSerial btSerial(bt_rx, bt_tx);


void setup()
{
  pinMode(ledf, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(leds, OUTPUT);
  Serial.begin(9600);
  btSerial.begin(9600);
}


void loop()
{
  char com;

  if (btSerial.available()){
    com = btSerial.read();
    Serial.write(com);
  }

  if (Serial.available()){
    com = Serial.read();
    btSerial.write(com);
  }

  if (com == 'f'){
    digitalWrite(ledf, HIGH);
  }
  else if (com == 'b'){
    digitalWrite(ledb, HIGH);
  }
  else if (com == 's'){
    digitalWrite(leds, HIGH);
  }
}
