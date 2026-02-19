int ledPin = 13;   // built-in LED
int val = 0;       // store analog value

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);   // start Serial at 9600 baud
}

void loop() {
  val = analogRead(A0);   // read potentiometer (0~1023)

  Serial.print("A0 value: ");
  Serial.println(val);    // print value to Serial Monitor

  digitalWrite(ledPin, HIGH);
  delay(val);             // delay depends on A0
  digitalWrite(ledPin, LOW);
  delay(val);
}
/* sẽ ra in ra kết quae quả không liên tục kiểu giá 
 trị nó không ổn định theo con số  analog điện áp động
 liên tục có giao động nhẹ nên không bao giừ iờ phẳng tuyệt  */
