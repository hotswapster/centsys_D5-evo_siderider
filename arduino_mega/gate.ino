void gatecontrol() {
  
}

// Variables for gate inputs
  int bbb4;
  int gcb4;
  int gob4;

void gateinputs() { //manage input behaviour and trigger serial status updates
  
  //json
  StaticJsonDocument<50> inputjson;
    
  //beam block behaviour
  bbb4 = beamblock; //store old value
  beamblock = digitalRead(bb_pin); //read new value
  if (beamblock != bbb4){ //if value changes, do something
      inputjson["beamblock"] = String(beamblock);
      serializeJson(inputjson, Serial);
      //serializeJson(inputjson, Serial1);
      /*
    if (beamblock == 1){
      Serial.println("Beam is blocked");
      Serial.println();
      }
    if (beamblock == 0){
      Serial.println("Beam is clear");
      Serial.println();
      
      }
    */
    bbb4 = beamblock;
  } 

  //gate closed behaviour
  gcb4 = gateclosed; //store old value
  gateclosed = digitalRead(gc_pin); //read new value
  if (gateclosed != gcb4){ //if value changes, do something
    
    inputjson["gateclosed"] = String(gateclosed);
    serializeJson(inputjson, Serial);
    //serializeJson(inputjson, Serial1);
    /*
    if (gateclosed == 1){Serial.println("Gate is closed");}
    if (gateclosed == 0){Serial.println("Gate is not closed");}
    */
    gcb4 = gateclosed;
  } 

  //gate open behaviour
  gob4 = gateopen; //store old value
  gateopen = digitalRead(go_pin); //read new value
  if (gateopen != gob4){ //if value changes, do something
    inputjson["gateopen"] = String(gateopen);
    serializeJson(inputjson, Serial);
    //serializeJson(inputjson, Serial1);
    /*
    if (gateopen == 1){Serial.println("Gate is open");}
    if (gateopen == 0){Serial.println("Gate is not open");}
    */
    gob4 = gateopen;
  }
  
} 

void statusdecode() {
  //put the flashing LED code in here - use debounce library which can detect couble clicks
}


// Manage outputs
void lockholidayon(int8_t pin) {
  digitalWrite(pin, HIGH);
  lockholiday = true;
  //Serial.println("Holiday Lock Enabled");
  outputjson["lockholiday"] = String(lockholiday);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void lockholidayoff(int8_t pin) {
  digitalWrite(pin, LOW);
  lockholiday = false;
  //Serial.println("Lock HOliday Disabled");
  outputjson["lockedholiday"] = String(lockholiday);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}
void lockopenon(int8_t pin) {
  digitalWrite(pin, HIGH);
  lockedopen = true;
  //Serial.println("Locked Open");
  outputjson["lockedopen"] = String(lockedopen);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void lockopenoff(int8_t pin) {
  digitalWrite(pin, LOW);
  lockedopen = false;
  //Serial.println("Locked Open Disabled");
  outputjson["lockedopen"] = String(lockedopen);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void triggeron(int8_t pin) { //Turns on here. Turns off in void loop on main page due not not figuring out how to manage the timer.
  triggertimer = millis();
  digitalWrite(pin, HIGH);
  trigger = true;
  //  Serial.println("Trigger Activated");
    
  outputjson["trigger"] = String(trigger);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void turnlighton(int8_t pin) {
  digitalWrite(pin, HIGH);
  lightson = true;
  //Serial.println("Lights On");
  
  outputjson["lightson"] = String(lightson);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
  
}

void turnlightoff(int8_t pin) {
  digitalWrite(pin, LOW);
  lightson = false;
   // Serial.println("Lights Off");
    
  outputjson["lightson"] = String(lightson);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void triggerped(int8_t pin) { //Turns on here. Turns off in void loop on main page due not not figuring out how to manage the timer.
  triggertimer = millis();
  digitalWrite(pin, HIGH);
  trigger = true;
  //  Serial.println("Pedestrian Trigger Activated");
    
  outputjson["triggerped"] = String(trigped);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void lockclosedon(int8_t pin) {
  digitalWrite(pin, HIGH);
  lockclosed = true;
  //Serial.println("Lock closed activated");
  outputjson["lockclosed"] = String(lockclosed);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}

void lockclosedoff(int8_t pin) {
  digitalWrite(pin, LOW);
  lockclosed = false;
  //Serial.println("Lock closed deactivated");
  outputjson["lockclosed"] = String(lockclosed);
  serializeJson(outputjson, Serial);
  //serializeJson(outputjson, Serial1);
}


void lockinposon() {
  lockholidayon(lockholiday_pin);
  lockopenon(lockopen_pin);
  lockclosedon(lockclosed_pin);
}

void resetalllocks() {
  lockholidayoff(lockholiday_pin);
  lockopenoff(lockopen_pin);
  lockclosedoff(lockclosed_pin);
}
