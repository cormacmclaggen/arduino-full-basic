#include <MsTimer2.h>

int onoff = 1;

void flash() {
  digitalWrite(13, onoff);
  onoff = !onoff;   // toggle between 1 and 0, ! operator inverts value
}

void setup() {
  pinMode(13, OUTPUT);
  MsTimer2::set(1000, flash);   // call flash() every 1 second
  MsTimer2::start();            // start timer
}

void loop() {
  // You can add other code here.
}
