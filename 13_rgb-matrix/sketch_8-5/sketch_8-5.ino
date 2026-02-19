byte col = 0;                 // Variable for column index (not used yet)
byte leds[8][8];              // 8x8 LED state array (reserved)

// pin[xx] = Arduino pin number connected to LED matrix pin xx
// -1 is a dummy value to make array index start from 1
int pins[17] = {
  -1,
  5, 4, 3, 2,
  14, 15, 16, 17,
  13, 12, 11, 10,
  9, 8, 7, 6
};

// rows[xx] = Arduino pin connected to ROW xx of LED matrix
int rows[8] = {
  pins[9], pins[14], pins[8], pins[12],
  pins[1], pins[7], pins[2], pins[5]
};

// cols[xx] = Arduino pin connected to COLUMN xx of LED matrix
int cols[8] = {
  pins[13], pins[3], pins[4], pins[10],
  pins[6], pins[11], pins[15], pins[16]
};

void setup() {
  // Set all LED matrix pins as OUTPUT
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // Initialize columns (Common Anode → HIGH = OFF)
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], HIGH);
  }

  // Initialize rows (LOW by default)
  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
}

void loop() {
  // Turn ON LEDs column by column
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[0], HIGH);   // Enable first row
    digitalWrite(cols[i], LOW);    // Enable column i (LED ON)
  }
}
