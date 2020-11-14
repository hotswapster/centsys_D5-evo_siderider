

// using switch only allows one character sent from serial. Sending this character from monitor will triggger relay.
//void myserial() {
//moved code to 1 serial read
//}

void fullstatusrequest(){
  Serial.print(String("{\"gate_pos\": \"" + String(gate_pos) + "\""));
  Serial.print(String(", \"beam\": \"" + String(beam) + "\""));
  Serial.print(String(", \"ledstatus\": \"" + String(ledstatus) + "\""));
  Serial.print(String(", \"beamblock\": " + String(beamblock)));
  Serial.print(String(", \"ding\": " + String(ding)));
  Serial.print(String(", \"dong\": " + String(dong)));
  Serial.print(String(", \"gateopen\": " + String(gateopen)));
  Serial.print(String(", \"gateclosed\": " + String(gateclosed)));
  Serial.print(String(", \"lightson\": " + String(lightson)));
  Serial.print(String(", \"lockedopen\": " + String(lockedopen)));
  Serial.print(String(", \"lockedinpos\": " + String(lockedinpos)));
  Serial.print(String(", \"temp\": " + String(temperature)));
  Serial.print(String(", \"lightlevel\": " + String(lightlevel)));
  Serial.println(String(", \"trigger\": " + String(trigger) + "}"));
}

void fullstatusrequesttomcu(){
  Serial1.print(String("{\"gate_pos\": \"" + String(gate_pos) + "\""));
  Serial1.print(String(", \"beam\": \"" + String(beam) + "\""));
  Serial1.print(String(", \"ledstatus\": \"" + String(ledstatus) + "\""));
  Serial1.print(String(", \"beamblock\": " + String(beamblock)));
  Serial1.print(String(", \"ding\": " + String(ding)));
  Serial1.print(String(", \"dong\": " + String(dong)));
  Serial1.print(String(", \"gateopen\": " + String(gateopen)));
  Serial1.print(String(", \"gateclosed\": " + String(gateclosed)));
  Serial1.print(String(", \"lightson\": " + String(lightson)));
  Serial1.print(String(", \"lockedopen\": " + String(lockedopen)));
  Serial1.print(String(", \"lockedinpos\": " + String(lockedinpos)));
  Serial1.print(String(", \"temp\": " + String(temperature)));
  Serial1.print(String(", \"lightlevel\": " + String(lightlevel)));
  Serial1.println(String(", \"trigger\": " + String(trigger) + "}"));
}


//serial port to nodemcu
void mcuserial() {
// Send message on serial on for testing
 // Serial1.write("watchdog\":\" \"OK"); this sent message over serial to mcu
  
  if (Serial1.available()){
    // Write what is received to the default serial port
   
    char ser = Serial1.read();
//    Serial.println("received");
    switch(ser){ 
      case '1': lockposon(lockinpos_pin); break;
      case '2': lockposoff(lockinpos_pin); break;
      case '3': lockopenon(lockopen_pin); break;
      case '4': lockopenoff(lockopen_pin); break;
      case '5': triggeron(trig_pin); break;
      case '7': turnlighton(lights_pin); break;
      case '8': turnlightoff(lights_pin); break;
      case '9': fullstatusrequest(); break;
      }
      Serial.println(String(ser));
    }
}
