void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  digitalWrite(9, ((val > 128) ? HIGH : LOW));
  delay(1000);
}

void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
//using only analog read and analogwrite
void loop() {
  int val = analogRead(A0);  // val ranges from 0 to 1023

  // Map the analog read value (0-1023) to PWM range (0-255)
  int pwmVal = map(val, 0, 1023, 0, 255);

  analogWrite(9, pwmVal);

  Serial.print("Analog Value: ");
  Serial.print(val);
  Serial.print(" => PWM Output: ");
  Serial.println(pwmVal);

  delay(1000);
}
