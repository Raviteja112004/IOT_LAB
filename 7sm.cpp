#include <Stepper.h>

const int ms = 10;
Stepper a(2048, 9, 10, 11, 12);

void setup() {
    a.setSpeed(ms);
}

void turn(int speed) {
    a.step(speed);
    delay(1000);
}

void loop() {
    turn(2048);
    turn(-2048);
}