#define LED_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, LOW);  // Turn ON LED
  delay(2000);                // 10 seconds

  digitalWrite(LED_PIN, HIGH); // Turn OFF LED
  delay(1
  000);                 // 3 seconds
}
