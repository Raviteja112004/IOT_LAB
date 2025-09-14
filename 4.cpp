int led = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(8);
  if (lastButtonState == HIGH && buttonState == LOW) {
    led = 1 - led;
    digitalWrite(13, (led ? HIGH : LOW));
  }
  lastButtonState = buttonState;
}
