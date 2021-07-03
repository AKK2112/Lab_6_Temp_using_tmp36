
#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;


uint16_t tempPin = A4;

double temperatureC = 0.0;

double temperatureF = 0.0;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
 pinMode(A4, INPUT);
 Serial.begin(9600);
  display.setup();

	display.clearDisplay();
	display.display();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  display.loop();
uint64_t reading = analogRead(A4);

double voltage = (reading * 3.3) / 4095.0;

double temperatureC = (voltage - 0.5) * 100;

double temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;


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