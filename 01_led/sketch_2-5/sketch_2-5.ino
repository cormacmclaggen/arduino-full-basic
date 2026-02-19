
void setup() {
  Serial.begin(9600);      // Start serial communication (baud rate: 9600)
  pinMode(13, OUTPUT);     // Set pin 13 as output
}

int i;                     // Variable to store received data

void loop() {
  if (Serial.available() > 0) {   // Check if data is available
    i = Serial.read();            // Read one byte from serial buffer
    Serial.println(i);            // Print received value

    if (i == '1') digitalWrite(13, HIGH);  // If '1' → LED ON
    if (i == '0') digitalWrite(13, LOW);   // If '0' → LED OFF
  }
}




/*Compared to the textbook version, this code uses a character variable 
 * instead of an integer and provides clear feedback messages on the 
 * Serial Monitor, making it more user-friendly and easier to understand.

  Serial.available()
returns the number of bytes currently waiting in the serial buffer> 0 → means that at least
one character has been received.

📌 If no data is available, the program does not read from the serial buffer, which helps prevent errors.
  Send commands from Serial Monitor:
  - '1' : turn LED ON
  - '0' : turn LED OFF
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   // Set built-in LED pin as output
  Serial.begin(9600);             // Start serial communication at 9600 baud
  Serial.println("Send 1 = LED ON, 0 = LED OFF");
}

void loop() {
  // Check if there is incoming data from Serial Monitor
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read one character from serial buffer

    if (command == '1') {
      digitalWrite(LED_BUILTIN, HIGH); // Turn LED ON
      Serial.println("LED is ON");
    }

    if (command == '0') {
      digitalWrite(LED_BUILTIN, LOW);  // Turn LED OFF
      Serial.println("LED is OFF");
    }
  }
}
