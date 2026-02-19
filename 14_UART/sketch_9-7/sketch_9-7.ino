int cds = A0;

void setup() {
  Serial.begin(9600);    // Initialize serial communication
}

void loop() {
  if (Serial.available()) {
    int received_data = Serial.read();

    if (received_data == 1) {
      int cdsValue = analogRead(cds);  // Read CDS sensor
      delay(1);

      if (cdsValue > 300) {
        Serial.write(1);   // Bright
      } else {
        Serial.write(0);   // Dark
      }
    }
  }
}
