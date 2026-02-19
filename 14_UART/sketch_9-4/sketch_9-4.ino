int pin_switch1 = 2;
int pin_switch2 = 3;
int pin_LED1 = 13;

boolean buttonState1 = false;
boolean buttonState2 = false;
boolean buttonState3 = false;

boolean buttonSwitch1_State_old = false;
boolean buttonSwitch2_State_old = false;

void setup() {
  Serial.begin(9600);

  Serial.print("Sketch: ");
  Serial.println(__FILE__);
  Serial.print("Uploaded: ");
  Serial.println(__DATE__);

  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_switch1, INPUT);
  pinMode(pin_switch2, INPUT);
}

void loop() {
  // ---- Switch 1 debounce (교재 방식) ----
  buttonState1 = digitalRead(pin_switch1); delay(1);
  buttonState2 = digitalRead(pin_switch1); delay(1);
  buttonState3 = digitalRead(pin_switch1); delay(1);

  if ((buttonState1 == buttonState2) && (buttonState1 == buttonState3)) {
    if (buttonState1 != buttonSwitch1_State_old) {
      buttonSwitch1_State_old = buttonState1;

      if (buttonSwitch1_State_old == HIGH) {
        Serial.write(1);
      } else {
        Serial.write(0);
      }
    }
  }

  // ---- Switch 2 debounce (교재 방식) ----
  buttonState1 = digitalRead(pin_switch2); delay(1);
  buttonState2 = digitalRead(pin_switch2); delay(1);
  buttonState3 = digitalRead(pin_switch2); delay(1);

  if ((buttonState1 == buttonState2) && (buttonState1 == buttonState3)) {
    if (buttonState1 != buttonSwitch2_State_old) {
      buttonSwitch2_State_old = buttonState1;

      if (buttonSwitch2_State_old == HIGH) {
        Serial.write(2);
      } else {
        Serial.write(3);
      }
    }
  }
}

/*VẤN ĐỀ
buttonState2=digitalRead(pin_switch1);
buttonState3=digitalRead(pin_switch1);
→ Đọc cùng 1 chân 3 lần
→ Mục đích: debounce, nhưng làm sai cách
Reference Code (debounce chuẩn – dễ hiểu)
bool lastState = LOW;

void loop() {
  bool current = digitalRead(pin_switch1);
  delay(10);

  if (current != lastState) {
    lastState = current;
    Serial.write(current ? 1 : 0);
  }
}*/
