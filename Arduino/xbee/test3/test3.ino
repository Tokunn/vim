int led[] = {12, 11, 10, 9};


void setup()
{
  for (int i = 0; i < 4; i++){
    pinMode(led[i], OUTPUT);
    }
  Serial.begin(9600);
}


void turnup_led(int mes)
{
  int chk = 0;
  digitalWrite(led[mes], HIGH);

  do{
    chk = Serial.read();
  }while (chk == mes);

  digitalWrite(led[mes], LOW);
}


void loop()
{
  if (Serial.available()){

    int mes;
    byte com = Serial.read();

    if (com == '0'){
      mes = 0;
    }
    else if (com == '1'){
      mes = 1;
    }
    else if (com == '2'){
      mes = 2;
    }
    else{
      mes = 3;
    }

    turnup_led(mes);
  }
}
