#include <Wire.h>

const int buttonPin = 2;    // Push button connected to digital pin 2
const int ledPin = 13;      // LED connected to digital pin 13
int buttonState = 0;        // Variable to store button state

void setup() {
  Wire.begin();             // Initialize I2C as master
  Serial.begin(9600);       // Start serial communication at 9600 bps
  pinMode(buttonPin, INPUT); // Set button pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
}

void loop() {
  // Read button state
  buttonState = digitalRead(buttonPin);

  // If button is pressed (LOW)
  if (buttonState == LOW) {

    // Request sensor data (humidity) via I2C
    Wire.beginTransmission(18); // Slave address 18
    Wire.write('H');             // Send request character 'H'
    Wire.endTransmission();

    // Request 2 bytes from slave
    Wire.requestFrom(18, 2);

    // Wait and read sensor data
    while (Wire.available()) {
      byte b = Wire.read();      // Read received byte
      Serial.println(int(b));    // Print received value
    }

    digitalWrite(ledPin, HIGH);  // Turn LED ON
    delay(1000);                 // Wait 1 second
  }
  else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF if button not pressed
  }

  delay(100);                    // Small delay
}
/*Purpose
When the button is pressed, the master:
Sends a request ('H') to the slave via I2C
Receives sensor data
Displays data on Serial Monitor
Turns LED ON*/