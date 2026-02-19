void setup(){
  pinMode(13, OUTPUT);
}

long pt = 0;    // previous time
int flag = 1;   // LED ON/OFF flag

void loop(){
  long ct = millis();   // current time

  if(ct - pt > 1000){   // check if 1 second has passed
    pt = ct;
    flag = !flag;
    digitalWrite(13, flag);
  }

  // You can add other code here.
}
