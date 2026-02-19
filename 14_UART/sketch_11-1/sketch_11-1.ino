#include <Wire.h>   // I2C communication library

void setup() {
  Wire.begin();        // Initialize as I2C master
  Serial.begin(9600); // Initialize serial monitor
}

void loop() {
  // Request 1 byte from slave with ID 8
  Wire.requestFrom(8, 1);

  while (Wire.available()) {
    byte b = Wire.read();     // Read received byte
    Serial.println(b);        // Print received value
  }

  delay(500); // Wait 500 ms
}
/*Purpose
Master requests data from slave
Displays received value via Serial Monitor*/