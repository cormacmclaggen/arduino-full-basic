G#include <SoftwareSerial.h>   // Software serial library

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);      // Set communication speed to 9600 bps
  pinMode(4, OUTPUT);        // Set pin 4 as LED output
}

int a;

void loop() {
  if (mySerial.available() > 0) {
    String m = mySerial.readString(); // Read incoming data as a string

    // If received value starts with '1'
    if (m.indexOf("1") == 0)
      digitalWrite(4, HIGH); // Turn LED ON

    // If received value starts with '0'
    if (m.indexOf("0") == 0)
      digitalWrite(4, LOW);  // Turn LED OFF
  }
}
/*Purpose
Receive commands from smartphone via Bluetooth
Control LED ON/OFF
⚠️ Note (không sửa code):
readString() is slow and may block execution*/
