void setup(){
  Serial.begin(9600);
}

long cnt, Mil;

void loop(){
  if (millis() - Mil >= 1000) {   // calculate 1 second interval
    Mil = millis();
    Serial.println(cnt++);
  }
}
