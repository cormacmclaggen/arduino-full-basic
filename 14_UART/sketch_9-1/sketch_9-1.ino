void setup() {
  // This function runs once when the Arduino starts
  Serial.begin(9600);   // Initialize serial communication at 9600 baud rate
}

void loop() {
  // This function runs repeatedly after setup()

  int LED_ON = 1;       // Value representing LED ON
  int LED_OFF = 0;      // Value representing LED OFF

  Serial.println(LED_ON);   // Send value '1' to the serial monitor
  delay(1000);              // Wait for 1 second

  Serial.println(LED_OFF);  // Send value '0' to the serial monitor
  delay(1000);              // Wait for 1 second
}

