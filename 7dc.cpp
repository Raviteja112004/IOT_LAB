void setup()
{
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void turn(int a) {
	digitalWrite(12, LOW);
 	digitalWrite(10, LOW);
  	digitalWrite(a, HIGH);
  	delay(2000);
}

void loop()
{
	turn(12);
 	turn(10);
}