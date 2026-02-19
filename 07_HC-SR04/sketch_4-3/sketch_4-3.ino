int trigPin = 2;
int echoPin = 3;

// Set serial speed, set trigPin as OUTPUT, echoPin as INPUT
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);   // Set trig pin as output
  pinMode(echoPin, INPUT);    // Set echo pin as input
}

void loop() {
  float duration, distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // Store the time that echoPin stays HIGH
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance using time
  // 340 m/s is the speed of sound
  // Divide by 2 because the wave travels forth and back
  distance = ((float)(340 * duration) / 10000) / 2;

  // Print duration and distance on Serial Monitor
  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDistance:");
  Serial.print(distance);
  Serial.println("cm\n");

  delay(500);
}
