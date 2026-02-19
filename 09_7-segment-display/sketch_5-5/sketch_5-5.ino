int num = 0;   // Current number displayed

// 7-segment codes (a b c d e f g dp)
// Common Cathode
byte numbers[10] = {
  0xFC, // 0
  0x60, // 1
  0xDA, // 2
  0xF2, // 3
  0x66, // 4
  0xB6, // 5
  0xBE, // 6
  0xE4, // 7
  0xFE, // 8
  0xF6  // 9
};

void displayNumber(int n) {
  int pin = 2;   // a → 2, b → 3, c → 4, d → 5, e → 6, f → 7, g → 8, dp → 9
  for (int i = 0; i < 8; i++) {
    boolean state = bitRead(numbers[n], 7 - i);
    digitalWrite(pin + i, state);
  }
}

void setup() {
  pinMode(12, INPUT);   // Push button (increase)
  pinMode(13, INPUT);   // Push button (decrease)

  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT); // 7-segment pins
  }

  digitalWrite(9, HIGH); // dp OFF
}

void loop() {

  // Increase number
  if (digitalRead(12) == HIGH) {
    ++num;
    if (num > 9) {
      num = 0;
    }
  }

  // Decrease number
  if (digitalRead(13) == HIGH) {
    --num;
    if (num < 0) {
      num = 9;
    }
  }

  displayNumber(num);
  delay(300);
}
