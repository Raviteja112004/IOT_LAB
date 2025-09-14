void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()) {
	char c = Serial.read();
    if(c == '1') {
	  digitalWrite(13, HIGH);
      Serial.println("LED is ON"); 
    } else if(c == '0') {
      digitalWrite(13, LOW);
      Serial.println("LED is OFF"); 
    } else {
      Serial.println("Invalid input"); 
    }
  }
}