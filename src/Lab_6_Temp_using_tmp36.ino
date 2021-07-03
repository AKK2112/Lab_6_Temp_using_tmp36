
#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;


uint16_t tempPin = A4;

double temperatureC = 0.0;

double temperatureF = 0.0;

void setup() {
 pinMode(A4, INPUT);
 Serial.begin(9600);
    //setting up display
    display.setup();
    display.clearDisplay();
    display.display();
}

void loop() {
  display.loop();
  //telling the board where the tmp36 is and what it should do with the values from the temp sensor. 
  uint64_t reading = analogRead(A4);

  double voltage = (reading * 3.3) / 4095.0;

  double temperatureC = (voltage - 0.5) * 100;

  double temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

    //displaying the temperatures to a mini OLED display for easy reading of the ambient temperature in my room.
    display.clearDisplay();

    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Inside temp (C):"); display.println(temperatureC);
    display.display();
    display.print("Inside temp (F):"); display.print(temperatureF);
    display.display();
    Serial.print(temperatureC); Serial.print(","); Serial.println(temperatureF);
delay(500);
}