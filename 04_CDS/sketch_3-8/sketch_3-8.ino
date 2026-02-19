void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);  // Read analog value
  Serial.println(sensorValue);

  if (sensorValue > 700) {
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
  }

  // delay(200); // optional
}

/*
 * 
 // Define pin connections
int cdsPin = A0;    // CDS (LDR) connected to analog pin A0
int ledPin = 4;     // LED connected to digital pin D4
int value = 0;      // Variable to store CDS value

void setup() {
  Serial.begin(9600);      // Start Serial Monitor at 9600 baud
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  // Read analog value from CDS (0 - 1023)
  value = analogRead(cdsPin);

  // Print CDS value to Serial Monitor
  Serial.println(value);

  // If it is dark, turn ON the LED
  // Dark = high resistance = high analog value
  if (value > 800) {
    digitalWrite(ledPin, LOW);  // LED OFF
  } 
  else {
    digitalWrite(ledPin, HIGH);   // LED ON
  }

  delay(300); // Wait 300 milliseconds
}
*/
