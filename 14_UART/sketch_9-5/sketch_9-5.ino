/*int pin_LED1 = 13;
int pin_LED2 = 12;
int received_data = 5;

void setup() {
  Serial.begin(9600);
  Serial.print("Sketch: "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println("START!!");

  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    received_data = Serial.read();

    if (received_data == 0) {
      digitalWrite(pin_LED1, LOW);
      Serial.println("Received Data 0");
    }

    if (received_data == 1) {
      digitalWrite(pin_LED1, HIGH);
      Serial.println("Received Data 1");
    }

    if (received_data == 2) {
      digitalWrite(pin_LED2, LOW);
      Serial.println("Received Data 2");
    }

    if (received_data == 3) {
      digitalWrite(pin_LED2, HIGH);
      Serial.println("Received Data 3");
    }
  }
}
*/
const int pin_switch1 = 2;
const int ledPin = 13;

bool lastButtonState = HIGH;
bool currentButtonState = HIGH;

// UART command state
char lastCmd = 0;

void setup() {
  pinMode(pin_switch1, INPUT_PULLUP);  // 안정적인 입력
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // -------- BUTTON DEBOUNCE --------
  bool r1 = digitalRead(pin_switch1);
  delay(10);
  bool r2 = digitalRead(pin_switch1);

  if (r1 == r2 && r1 != lastButtonState) {
    lastButtonState = r1;

    // 버튼 눌림 (LOW)
    if (r1 == LOW) {
      Serial.write('1');   // send command
      digitalWrite(ledPin, HIGH);
    }
  }

  // -------- UART RECEIVE --------
  if (Serial.available()) {
    char cmd = Serial.read();

    // validate command
    if ((cmd == '0' || cmd == '1') && cmd != lastCmd) {
      lastCmd = cmd;

      if (cmd == '1') {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
    }
  }
}
