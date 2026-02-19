void setup() {
  Serial.begin(9600);       // Initialize serial communication
  pinMode(13, OUTPUT);     // Set pin 13 as LED output
}

void loop() {
  if (Serial.available()) {         // Check if data is available
    int received_data = Serial.read();  // Read received data
    Serial.println(revived_data); // ❌ typo: revived_data

    // book: Serial.println(revived_data);    // Print received data (typo in original code)

    if (received_data == 1) {
      digitalWrite(13, HIGH);        // Turn LED ON if data is '1'
    } else {
      digitalWrite(13, LOW);         // Turn LED OFF otherwise
    }
  }
}

