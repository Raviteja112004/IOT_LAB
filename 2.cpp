const int r = 13, y = 11, g = 9;
void setup()
{
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void light(int a) {
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
  digitalWrite(a, HIGH);
  delay(1000);
}

void loop()
{
  light(r);
  light(y);
  light(g);
}