#define AXISXPIN 0
#define AXISYPIN 1

#ifndef M_PI
#define M_PI 3.14159265358979
#endif

double gosaX = -15;
double gosaY = -18;


void setup()
{
  Serial.begin(9600);
}


double Map( int iIn, int iIn1, int iIn2, double dOut1, double dOut2, boolean bConstrain = false )
{
  double dValue = (iIn - iIn1) * (dOut2 - dOut1) / (iIn2 - iIn1) + dOut1;
  if (bConstrain)
  {
    double dOutMin, dOutMax;
    if( dOut1 < dOut2 )
    {
      dOutMin= dOut1;
      dOutMax= dOut2;
    }
    else
    {
      dOutMin= dOut2;
      dOutMax= dOut1;
    }
    if( dOutMin > dValue )
    {
      return dOutMin;
    }
    if( dOutMax < dValue )
    {
      return dOutMax;
    }
  }
  return dValue;
}


void make_com(char *com, double katamukiX, double katamukiY)
{
  if (katamukiX > 10){
    com[0] = 'f';
  }
  else if (katamukiX < -10){
    com[0] = 'b';
  }
  else {
    com[0] = '0';
  }

  if (katamukiY > 20){
    com[1] = 'l';
  }
  else if (katamukiY < -20){
    com[1] = 'r';
  }
  else {
    com[1] = 's';
  }

  double kataX = katamukiX * katamukiX;
  double six = 50*50;
  double five = 40*40;
  double four = 30*30;
  double three = 20*20;
  double two = 10*10;

  if (kataX > six){
    com[2] = '5';
  }
  else if (kataX > five){
    com[2] = '4';
  }
  else if (kataX > four){
    com[2] = '3';
  }
  else if (kataX > three){
    com[2] = '2';
  }
  else if (kataX > two){
    com[2] = '1';
  }
  else {
    com[2] = '1';
  }

}


void loop()
{
  int iValueX = analogRead(AXISXPIN);
  int iValueY = analogRead(AXISYPIN);


  double dSinX = Map( iValueX, 301, 721, -1.0, 1.0, true );
  double dSinY = Map( iValueY, 308, 736, -1.0, 1.0, true );

  double dAngleX = asin(dSinX) * 180.0 / M_PI;
  double dAngleY = asin(dSinY) * 180.0 / M_PI;

  double katamukiX = dAngleX - gosaX;
  double katamukiY = dAngleY - gosaY;


  char com[3];
  make_com(com, katamukiX, katamukiY);

  if (com[0] != '0' || com[1] != 's'){
    Serial.print(com[0]);
    Serial.print(com[1]);
    Serial.print(com[2]);
    Serial.println();
  }


}
