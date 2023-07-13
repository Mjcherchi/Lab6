#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#define TEMP A4

OledWingAdafruit display;

void setup()
{
  pinMode(TEMP, INPUT);
  display.setup();
}

void loop()
{
  display.loop();
  {
    uint16_t reading = analogRead(TEMP);
    double voltage = (reading * 3.3) / 4095.0;
    double temperatureC = (voltage - 0.5) * 100;
    double temperatureF = (temperatureC)*1.8 + 32;

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(temperatureF);

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(temperatureC);

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(65, 0);
    display.println("F");

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(65, 16);
    display.println("C");

    display.display();
  }
}

// hi

// void setup() {
// display.setup();

// display.clearDisplay();
// display.display();
//}

// uint64_t reading = analogRead(A4);
// double voltage = (reading * 3.3) / 4095.0;
// double temperature = (voltage - 0.5) * 100;