#define AXISXPIN 0
#define AXISYPIN 1
#define AXISZPIN 2

#ifndef M_PI
#define M_PI 3.14159265358979
#endif


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


void loop()
{
  int iValueX = analogRead(AXISXPIN);
  int iValueY = analogRead(AXISYPIN);
  int iValueZ = analogRead(AXISZPIN);


  double dSinX = Map( iValueX, 301, 721, -1.0, 1.0, true );
  double dSinY = Map( iValueY, 308, 736, -1.0, 1.0, true );
  double dSinZ = Map( iValueZ, 379, 775, -1.0, 1.0, true );

  double dAngleX = asin(dSinX) * 180.0 / M_PI;
  double dAngleY = asin(dSinY) * 180.0 / M_PI;
  double dAngleZ = asin(dSinZ) * 180.0 / M_PI;

  Serial.print( "Angle[deg] : " );
  Serial.print( dAngleX );
  Serial.print( ", " );
  Serial.print( dAngleY );
  Serial.print( ", " );
  Serial.print( dAngleZ );
  Serial.print( "\n" );
  Serial.print( "\n" );

  delay(10);
}
