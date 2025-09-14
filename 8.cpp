#define bpin 8
#define tpin 9
#define epin 10

void setup() {
  Serial.begin(9600);
  pinMode(epin, INPUT);
  pinMode(bpin, OUTPUT);
  pinMode(tpin, OUTPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(tpin, LOW);
  delayMicroseconds(2);
  digitalWrite(tpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);

  duration = pulseIn(epin, HIGH);
  distance = duration / 58.2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print("\n");

  if(distance < 50) {
    tone(bpin, 1000);
  } else {  
    noTone(bpin);
  }
  delay(250);
}

