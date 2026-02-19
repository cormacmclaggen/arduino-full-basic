#include <SoftwareSerial.h>   // Include SoftwareSerial library

SoftwareSerial mySerial(10, 11); // RX, TX pins for software serial

void setup() {
  // Initialize hardware serial communication
  Serial.begin(9600);
  Serial.println("Hi, serial!");  // Display message on Serial Monitor

  // Initialize software serial communication
  mySerial.begin(9600);
  mySerial.println("Hello, world?"); // Send message via software serial
}

void loop() {
  // If data is available from software serial
  if (mySerial.available()) {
    Serial.write(mySerial.read()); // Forward data to hardware serial
  }

  // If data is available from hardware serial
  if (Serial.available()) {
    mySerial.write(Serial.read()); // Forward data to software serial
  }
}
