/*
  Serial LED Mode Control (Built-in LED)

  Commands from Serial Monitor:
  0 = LED OFF
  1 = LED ON
  2 = Blink continuously every 500 ms
  3 = Blink continuously every 1000 ms
  4 = ON for 1000 ms, OFF for 500 ms
*/

int mode = 0;                 // Current LED mode
unsigned long previousTime = 0;
bool ledState = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED as output
  Serial.begin(9600);            // Start serial communication

  Serial.println("LED MODE CONTROL");
  Serial.println("0: OFF");
  Serial.println("1: ON");
  Serial.println("2: Blink 300 ms");
  Serial.println("3: Blink 500 ms");
  Serial.println("4: ON 500 ms / OFF 250 ms");
}

void loop() {
  // Read command from Serial Monitor
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd >= '0' && cmd <= '4') {
      mode = cmd - '0';          // Convert char to number
      Serial.print("Mode set to: ");
      Serial.println(mode);
    }
  }

  unsigned long currentTime = millis();

  // MODE 0: LED OFF
  if (mode == 0) {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // MODE 1: LED ON
  else if (mode == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  // MODE 2: Blink every 300 ms
  else if (mode == 2) {
    if (currentTime - previousTime >= 300) {
      previousTime = currentTime;
      ledState = !ledState;
      digitalWrite(LED_BUILTIN, ledState);
    }
  }

  // MODE 3: Blink every 500 ms
  else if (mode == 3) {
    if (currentTime - previousTime >= 500) {
      previousTime = currentTime;
      ledState = !ledState;
      digitalWrite(LED_BUILTIN, ledState);
    }
  }

  // MODE 4: ON 500 ms, OFF 250 ms
  else if (mode == 4) {
    if (ledState == HIGH && currentTime - previousTime >= 500) {
      ledState = LOW;
      previousTime = currentTime;
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if (ledState == LOW && currentTime - previousTime >= 250) {
      ledState = HIGH;
      previousTime = currentTime;
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
