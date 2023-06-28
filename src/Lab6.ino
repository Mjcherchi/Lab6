#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

uint16_t reading = analogRead(A4);
double voltage = (reading * 3.3) / 4095.0;
double temperatureC = (voltage - 0.5) * 100;
double temperatureF = (temperatureC)*1.8 + 32;

OledWingAdafruit display;

void setup()
{
  pinMode(A4, INPUT);
}

void loop()
{
  display.loop();
  {
    display.setup();
    display.clearDisplay();

    display.display();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(temperatureF);
    display.display();
  }
  delay(100000000);
}

// OledWingAdafruit display;

// void setup() {
// display.setup();

// display.clearDisplay();
// display.display();
//}

// uint64_t reading = analogRead(A4);
// double voltage = (reading * 3.3) / 4095.0;
// double temperature = (voltage - 0.5) * 100;