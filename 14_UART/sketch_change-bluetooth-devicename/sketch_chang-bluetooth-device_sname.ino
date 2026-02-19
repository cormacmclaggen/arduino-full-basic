#include <SoftwareSerial.h>

SoftwareSerial HM10(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  HM10.begin(9600);   // baud mặc định HM-10

  Serial.println("HM-10 ready");
}

void loop() {
  if (HM10.available()) {
    Serial.write(HM10.read());
  }

  if (Serial.available()) {
    HM10.write(Serial.read());
  }
}
