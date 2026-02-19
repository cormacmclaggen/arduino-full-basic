void setup() {
  pinMode(13, OUTPUT);   // Set pin 13 as OUTPUT
}

void loop() {
  digitalWrite(13, HIGH); // LED ON
  delay(500);             // wait 500 ms

  digitalWrite(13, LOW);  // LED OFF
  delay(500);             // wait 500 ms
}
