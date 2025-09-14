#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

unsigned long prevMillis = 0;
const unsigned long interval = 1000;
int sec = 0, minu = 0, hr = 0, day = 1, mon = 1, yr = 2023;

int page = 0;                  // which page to display
unsigned long lastPageSwitch = 0;
const unsigned long pageInterval = 3000; // switch page every 3s

void setup()
{
    lcd.init();
    lcd.backlight();
    dht.begin();
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
}

void loop()
{
    if (millis() - prevMillis >= interval)
    {
        prevMillis = millis();
        updateDateTime();
    }

    if (millis() - lastPageSwitch >= pageInterval)
    {
        lastPageSwitch = millis();
        page = 1 - page; // toggle between 0 and 1
        lcd.clear();
    }

    float t = dht.readTemperature();

    if (page == 0)
    {
        // Page 1: Temperature + Time
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(isnan(t) ? 0 : t, 1);
        lcd.print("C   ");

        lcd.setCursor(0, 1);
        printTime();
    }
    else
    {
        // Page 2: Date
        lcd.setCursor(0, 0);
        lcd.print("Date: ");
        print2digit(day);
        lcd.print("/");
        print2digit(mon);
        lcd.print("/");
        lcd.print(yr);

        lcd.setCursor(0, 1);
        lcd.print("Time: ");
        printTime();
    }

    delay(200);
}

void updateDateTime()
{
    if(++sec < 60) return;
    sec = 0;
    if(++minu < 60) return;
    minu = 0;
    if(++hr < 24) return;
    hr = 0;
    if(++day <= daysInMonth(mon)) return;
    day = 1;
    if(++mon > 12) {
        mon = 1;
        yr++;
    }
}

int daysInMonth(int m)
{
    if (m == 2) return 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

void printTime()
{
    print2digit(hr);
    lcd.print(":");
    print2digit(minu);
    lcd.print(":");
    print2digit(sec);
}

void print2digit(int v)
{
    if (v < 10) lcd.print("0");
    lcd.print(v);
}
