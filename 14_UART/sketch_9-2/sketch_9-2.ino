void setup() {
  Serial.begin(9600);   // Initialize serial communication
}

void loop() {
  int LED_ON = 1;       // Data value for LED ON
  int LED_OFF = 0;      // Data value for LED OFF

  Serial.write(LED_ON);      // Send '1' to Arduino 2 (slave)
  Serial.println(LED_ON);    // Display '1' on serial monitor
  delay(1000);               // Wait 1 second

  Serial.write(LED_OFF);     // Send '0' to Arduino 2 (slave)
  Serial.println(LED_OFF);   // Display '0' on serial monitor
  delay(1000);               // Wait 1 second
}
