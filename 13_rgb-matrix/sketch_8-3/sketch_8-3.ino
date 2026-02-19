byte col = 0;
byte leds[8][8];

// pin[xx] = Arduino pin number connected to LED matrix
// (-1 is a dummy value to make the array start from index 1)
int pins[17] = { 
  -1, 5, 4, 3, 2, 14, 15, 16, 
  17, 13, 12, 11, 10, 9, 8, 7, 6 
};

// row[xx] of LEDs = pin number connected to matrix rows
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12],
  pins[1], pins[7], pins[2], pins[5]
};

// col[xx] of LEDs = pin number connected to matrix columns
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10],
  pins[6], pins[11], pins[15], pins[16]
};

void setup() {
  // Set all matrix pins as OUTPUT
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // Initialize all columns to HIGH (OFF state)
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], HIGH);
  }

  // Initialize all rows to LOW
  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
}

void loop() {
  // Dot Matrix Common Cathode and Common Anode test
  digitalWrite(rows[1], HIGH);   // Activate row 2
  digitalWrite(cols[1], LOW);    // Turn on LED at column 2
  digitalWrite(cols[2], LOW);    // Turn on LED at column 3
}
