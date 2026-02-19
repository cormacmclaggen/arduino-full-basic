#include <Wire.h>

byte x = 0;

void setup() {
  Wire.begin();        // Initialize as I2C master
  Serial.begin(9600);
}

void loop() {
  // Start transmission to slave with ID 8
  Wire.beginTransmission(8);

  Wire.write("x is "); // Send text (5 bytes)
  Wire.write(x);       // Send numeric value

  Wire.endTransmission(); // End transmission

  x++;                 // Increase value
  delay(500);
  Serial.println(x);   // Display value
}
/*Purpose
Master sends string + data byte to slave*/