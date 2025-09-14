#include <SoftwareSerial.h>

// SIM900 connections:
// TX of SIM900 -> Pin 10 on Arduino (RX)
// RX of SIM900 -> Pin 11 on Arduino (TX)
SoftwareSerial sim900(10, 11); // RX, TX

void setup() {
  // Start communication with serial monitor
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Start communication with SIM900 module
  sim900.begin(9600);
  delay(1000);

  // Give SIM900 time to register on the network
  sim900.println("AT");
  delay(1000);
  sim900.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  sim900.println("AT+CSCS=\"GSM\""); // Set SMS character set
  delay(1000);
  sim900.println("AT+CMGS=\"+919164499334\""); // Replace with recipient number
  delay(1000);

  sim900.print("Hi Ma'am! How are you?"); // Message content
  delay(1000);

  sim900.write(26); // ASCII code of CTRL+Z to send SMS
  delay(5000);

  Serial.println("SMS Sent!");
}

void loop() {
  // Do nothing
}