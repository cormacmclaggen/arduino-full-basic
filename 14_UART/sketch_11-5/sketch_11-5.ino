#include <Wire.h>

#define SLAVE_ADDR 9   // Slave I2C address

int analogPin = 0;
int val = 0;

void setup() {
  Wire.begin();        // Initialize as I2C master
}

void loop() {
  delay(50);

  // Map analog value (0–1023) to range 1–255
  val = map(analogRead(analogPin), 0, 1023, 255, 1);

  // Send value to slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();
}
/**Purpose
Send potentiometer value to slave
Control LED blink speed remotely/