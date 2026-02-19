#include "Timer.h"

Timer t;      // instantiate timer object
Timer led;    // timer for analogRead function

void setup(void){
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  t.oscillate(13, 1000, HIGH);   // toggle every 1 second
  led.every(100, readData);      // call readData every 100 ms
}

void loop(){
  t.update();
  led.update();
}

void readData(){
  Serial.println(analogRead(A0));
}
