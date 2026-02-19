#include <Wire.h>

void setup() {
  Wire.begin(8);                    // Initialize as slave with ID 8
  Wire.onReceive(receiveEvent);     // Register receive event
  Serial.begin(9600);
}

void loop() {
  delay(100); // Idle loop
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) {    // Read all but last byte
    char c = Wire.read();           // Read byte as character
    Serial.print(c);                // Print character
  }

  int x = Wire.read();              // Read last byte as integer
  Serial.println(x);                // Print integer value
}
/*Purpose
Receive mixed string + number via I2C*/
