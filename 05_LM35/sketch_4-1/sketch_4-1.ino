int lm35Pin = A0;
int value;

void setup() {
  Serial.begin(9600);   // Start Serial Monitor
}

void loop() {
  value = analogRead(lm35Pin);

  // Convert analog value to voltage (V)
  float voltage = value * 5.0 / 1024.0;

  // Convert voltage to temperature (°C)
  float temperature = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);
}
