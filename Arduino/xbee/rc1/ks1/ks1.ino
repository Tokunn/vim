char com[] = {"0s1", "0s2", "0s3", "0s4", "0s5",
              "0l1", "0l2", "0l3", "0l4", "0l5",
              "0r1", "0r2", "0r3", "0r4", "0r5",
              "fs1", "fs2", "fs3", "fs4", "fs5",
              "fl1", "fl2", "fl3", "fl4", "fl5",
              "fr1", "fr2", "fr3", "fr4", "fr5",
              "bs1", "bs2", "bs3", "bs4", "bs5",
              "bl1", "bl2", "bl3", "bl4", "bl5",
              "br1", "br2", "br3", "br4", "br5"};


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  for (int i = 0; i < 45; i++){
    Serial.println(com[i]);
    delay(500);
  }
}
