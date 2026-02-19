byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to Arduino pin number
// (-1 is dummy to make array start at index 1)
int pins[17] = {
  -1, 5, 4, 3, 2, 14, 15, 16, 17,
  13, 12, 11, 10, 9, 8, 7, 6
};

// row[xx] of LEDs = pin yy on LED matrix
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12],
  pins[1], pins[7], pins[2], pins[5]
};

// col[xx] of LEDs = pin yy on LED matrix
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10],
  pins[6], pins[11], pins[15], pins[16]
};

void setup() {
  // set all used pins as OUTPUT
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // initialize columns (OFF)
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], HIGH);   // Common Anode → HIGH = OFF
  }

  // initialize rows (OFF)
  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);    // LOW = OFF
  }
}

void loop() {
  // Turn ON LEDs by COLUMN direction
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], HIGH);   // supply power to row
    digitalWrite(cols[0], LOW);    // activate column 0
  }
}
