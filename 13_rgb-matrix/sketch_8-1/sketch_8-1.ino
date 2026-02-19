#define LED_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn ON LED
  delay(10000);                // 10 seconds

  digitalWrite(LED_PIN, LOW);  // Turn OFF LED
  delay(3000);                 // 3 seconds
}
//common cathode
