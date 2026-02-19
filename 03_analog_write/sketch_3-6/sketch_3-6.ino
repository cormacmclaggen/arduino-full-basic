int ledPin = 13;   // LED is connected to pin 13 (built-in LED)
int val = 0;       // Variable to store the analog value

void setup() {
  pinMode(ledPin, OUTPUT);   // Set LED pin as OUTPUT;
}


void loop() {
  val = analogRead(A0);      // Read analog value from potentiometer (0~1023)

  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(val);                 // Wait for 'val' milliseconds

  digitalWrite(ledPin, LOW);  // Turn LED OFF
  delay(val);                 // Wait for 'val' milliseconds
}
