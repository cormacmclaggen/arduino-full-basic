void setu(){
  Serial.begin(9600);
  
}
void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(200);
}



/*int cdsPin = A0;
int ledPin = 4;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  value = analogRead(cdsPin);
  Serial.println(value);

  // Nếu tối (giá trị lớn) thì bật LED
  if (value > 600) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}
*/
