// HC-SR04 + Buzzer example
// TRIG -> D2
// ECHO -> D3
// BUZZER -> D4

#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance (cm)
  distance = duration / 58;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object is closer than 20 cm, turn buzzer ON
  if (distance > 0 && distance < 20) {
    digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF
  }

  delay(200);
}
/* if (distance > 0 && distance < 50) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(distance * 5);      // closer = faster beep
  digitalWrite(BUZZER_PIN, LOW);
  delay(distance * 5);
} else {
  digitalWrite(BUZZER_PIN, LOW);
}
As the distance decreases, the beeping frequency increases
*/
