#include <Wire.h>

#define SLAVE_ADDR 9   // Slave I2C address

int LED = 13;          // LED pin
int rd;                // Received data
int br;                // Blink rate

void setup() {
  pinMode(LED, OUTPUT);

  // Initialize I2C communication as slave
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void receiveEvent() {
  rd = Wire.read();        // Read received value
  Serial.println(rd);     // Print received value
}

void loop() {
  delay(50);

  // Convert received value to delay time
  br = map(rd, 1, 255, 100, 2000);

  digitalWrite(LED, HIGH);
  delay(br);
  digitalWrite(LED, LOW);
  delay(br);
}
/*Purpose
Receive speed value from master
Blink LED faster/slower based on received data*/