#include <SD.h>

const int chipSelect = 4;

void setup()
{
  Serial.begin(9600);
  
  Serial.print(F("Initializing SD card..."));

  pinMode(SS, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println(F("Card failed, or not present"));
    while(1);
  }
  Serial.println(F("ok."));

  SdFile::dateTimeCallback( &dateTime );
}

void loop()
{
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    int value = analogRead(0);
    dataFile.println(value);
    dataFile.close();
    
    Serial.println(value);
  }

  delay(1000);
}

void dateTime(uint16_t* date, uint16_t* time)
{
  uint16_t year = 2013;
  uint8_t month = 2, day = 3, hour = 9, minute = 0, second = 0;

  // GPSやRTCから日付と時間を取得
  // FAT_DATEマクロでフィールドを埋めて日付を返す
  *date = FAT_DATE(year, month, day);

  // FAT_TIMEマクロでフィールドを埋めて時間を返す
  *time = FAT_TIME(hour, minute, second);
}
