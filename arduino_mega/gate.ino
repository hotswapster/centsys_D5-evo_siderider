void gatecontrol() {
  
}

// Variables for gate inputs
  int bbb4;
  int gcb4;
  int gob4;

void gateinputs() { //manage input behaviour and trigger serial status updates
  //beam block behaviour
  bbb4 = beamblock; //store old value
  beamblock = digitalRead(bb_pin); //read new value
  if (beamblock != bbb4){ //if value changes, do something
    if (beamblock == 1){Serial.println("Beam is blocked");}
    if (beamblock == 0){Serial.println("Beam is clear");}
    bbb4 = beamblock;
  } 

  //gate closed behaviour
  gcb4 = gateclosed; //store old value
  gateclosed = digitalRead(gc_pin); //read new value
  if (gateclosed != gcb4){ //if value changes, do something
    if (gateclosed == 1){Serial.println("Gate is closed");}
    if (gateclosed == 0){Serial.println("Gate is not closed");}
    gcb4 = gateclosed;
  } 

  //gate open behaviour
  gob4 = gateopen; //store old value
  gateopen = digitalRead(go_pin); //read new value
  if (gateopen != gob4){ //if value changes, do something
    if (gateopen == 1){Serial.println("Gate is closed");}
    if (gateopen == 0){Serial.println("Gate is not closed");}
    gob4 = gateopen;
  }
  
} 

void statusdecode() {
  //put the flashing LED code in here
}


// Manage outputs
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

void triggeron(int8_t pin) { //Turns on here. Turns off in void loop on main page due not not figuring out how to manage the timer.
  triggertimer = millis();
  digitalWrite(pin, HIGH);
  trigger = true;
    Serial.println("Trigger Activated");
}

void turnlighton(int8_t pin) {
  digitalWrite(pin, HIGH);
  lightson = true;
  Serial.println("Lights On");
}

void turnlightoff(int8_t pin) {
  digitalWrite(pin, LOW);
  lightson = false;
    Serial.println("Lights Off");
}
