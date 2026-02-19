/*
 * Serial.begin(9600);  Starts serial communication between Arduino and the computer
                        The Serial Monitor baud rate must be 9600

   analogRead(A0);      Reads the analog voltage from pin A0
                        Returns a value from 0 to 1023: 0 ≈ 0V >> 1023 ≈ 5V

  Serial.println(a);    Prints the value of variable a to the Serial Monitor
                        Each value is printed on a new line
  delay(100);           Waits for 100 milliseconds to makes the output easier to read
 */
void setup() {
  Serial.begin(9600);   // Start serial communication
}

void loop() {
  int a = analogRead(A0);  // Read analog value from A0 (0~1023)
  Serial.println(a);       // Print value to Serial Monitor
  delay(100);              // Wait 100 ms
}
