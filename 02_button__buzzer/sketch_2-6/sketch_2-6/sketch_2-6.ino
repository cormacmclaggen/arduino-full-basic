int inPin = 4;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
    
}
void loop(){
  val=digitalRead(inPin);
  Serial.println(val);
  delay(100);
}
