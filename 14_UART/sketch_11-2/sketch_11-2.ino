#include <Wire.h>

byte b = 0;

void setup() {
  Wire.begin(8);                 // Initialize as slave with ID 8
  Wire.onRequest(requestEvent); // Register request event handler
  Serial.begin(9600);
}

void loop() {
  // No repeated code needed
}

void requestEvent() {
  Wire.write(b++);        // Send incrementing byte value
  Serial.println(b);      // Print sent value
}
/*Purpose
Slave sends one byte to master when requested
Demonstrates I2C slave response*/