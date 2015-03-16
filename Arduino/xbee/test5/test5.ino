int fro_rea[] = {3, 4};
int lef_rig[] = {6, 7};
int speed[] = {9, 10, 11};


void setup()
{
  for (int i = 0; i < 14; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}


class MakeCommando{
  private:
    boolean fro_rea_dec[][] = {{HIGH, LOW}, {LOW, HIGH}, {LOW, LOW}};
    boolean lef_rig_dec[][] = {{HIGH, LOW}, {LOW, HIGH}, {LOW, LOW}};
    boolean speed_dec[][] = {{LOW , LOW , LOW },
                             {HIGH, LOW , HIGH},
                             {HIGH, LOW , LOW },
                             {HIGH, HIGH, HIGH},
                             {HIGH, HIGH, LOW }};
    char str[3];
  public:
    MakeCommando();
    void analyze_str(int* dec_num);
    void action(int dec_num);
};


MakeCommando::MakeCommando()
{
  int i = 0;
  char chunk;
  char *buf = str;
  while (1) {
    if (Serial.available()) {
      chunk = Serial.read();
      buf[i] = c;
      if (i == 2) break;
      i++
    }
  }
  buf[3] = '\0';
}


int main()
{
  cout << "Hello\n";
}
