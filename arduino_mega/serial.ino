

// using switch only allows one character sent from serial. Sending this character from monitor will triggger relay.
void myserial (){
  if (Serial.available()) {
    char ser = Serial.read();
//    Serial.println("received");
    switch(ser){ 
      case '1':  lockposon(lockinpos_pin); break;
      case '2':  lockposoff(lockinpos_pin); break;
      case '3': lockopenon(lockopen_pin); break;
      case '4': lockopenoff(lockopen_pin); break;
      case '5': triggeron(trig_pin); break;
      case '7': turnlighton(lights_pin); break;
      case '8': turnlightoff(lights_pin); break;
}
}
}
void lockposon(int8_t pin) {
  digitalWrite(pin, HIGH);
  Serial.println("Lock in Position - locked");
}

void lockposoff(int8_t pin) {
  digitalWrite(pin, LOW);
    Serial.println("Lock in Position - unlocked");
}
void lockopenon(int8_t pin) {
  digitalWrite(pin, HIGH);
  Serial.println("Locked Open");
}

void lockopenoff(int8_t pin) {
  digitalWrite(pin, LOW);
    Serial.println("Locked Open Disabled");
}

void triggeron(int8_t pin) {
  triggertimer = millis();
  digitalWrite(pin, HIGH);
  trigger = true;
    Serial.println("Trigger Activated");
}

void turnlighton(int8_t pin) {
  digitalWrite(pin, HIGH);
  Serial.println("Lights On");
}

void turnlightoff(int8_t pin) {
  digitalWrite(pin, LOW);
    Serial.println("Lights Off");
}

/*
lockinpos_pin = 40; // serial 1 lock, 2 unlock
lockopen_pin = 41;  // serial 3 lock, 4 unlock
trig_pin = 42;      // serial 5 trigger
lights_pin = 43;    // serial 7 on, 8 off

  */
