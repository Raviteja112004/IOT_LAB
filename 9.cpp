#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address might be 0x3F for some displays

// DHT setup
#define DHTPIN 2       // DHT11 data pin connected to Arduino pin 2
#define DHTTYPE DHT11  // Sensor type
DHT dht(DHTPIN, DHTTYPE);

String dateTime = "";

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Waiting for time");
}

void loop() {
  if (Serial.available()) {
    dateTime = Serial.readStringUntil('\n');  // Read incoming date/time from Python

    // Display Date and Time
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(dateTime.substring(0, 10));  // dd-mm-yyyy
    lcd.setCursor(0, 1);
    lcd.print(dateTime.substring(11));     // HH:MM:SS

    delay(2000);  // Display time for 2 seconds

    // Read DHT11 sensor values
    float temperature = dht.readTemperature();  // °C
    float humidity = dht.readHumidity();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(isnan(temperature) ? "N/A" : String(temperature, 1));
    lcd.print((char)223); // Degree symbol
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.print(isnan(humidity) ? "N/A" : String(humidity, 0));
    lcd.print("%");

    delay(3000);  // Display temp/humidity for 3 seconds
  }
}