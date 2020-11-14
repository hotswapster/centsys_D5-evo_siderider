// serial = USB | serial1 = connection to nodeMCU


// using switch only allows one character sent from serial. Sending this character from monitor will triggger relay.
//void myserial() {
//moved code to 1 serial read
//}

void fullstatusrequest(){
  StaticJsonDocument<250> statusjson;
  statusjson["gp"] = String(gate_pos);
  statusjson["b"] = String(beam);
  statusjson["st"] = String(ledstatus);
  statusjson["bb"] = String(beamblock);
  statusjson["ding"] = String(ding);
  statusjson["dong"] = String(dong);
  statusjson["go"] = String(gateopen);
  statusjson["gc"] = String(gateclosed);
  statusjson["l"] = String(lightson);
  statusjson["lo"] = String(lockedopen);
  statusjson["lp"] = String(lockedinpos);
  statusjson["t"] = String(temperature);
  statusjson["ll"] = String(lightlevel);
  statusjson["t"] = String(trigger);

  serializeJson(statusjson, Serial);
  serializeJson(statusjson, Serial1);
  //serializeJson(statusjson, Serial1);
}

void fullstatusrequesttomcu(){ //send multiple times as nodemcu only accepts 64 characters
  StaticJsonDocument<256> statusjson;
  statusjson["gate_pos"] = String(gate_pos);
  statusjson["beam"] = String(beam);
  statusjson["ledstatus"] = String(ledstatus);
  statusjson["beamblock"] = String(beamblock);
  statusjson["ding"] = String(ding);
  statusjson["dong"] = String(dong);
  statusjson["gateopen"] = String(gateopen);
  statusjson["gateclosed"] = String(gateclosed);
  statusjson["lightson"] = String(lightson);
  statusjson["lockedopen"] = String(lockedopen);
  statusjson["lockedinpos"] = String(lockedinpos);
  statusjson["temp"] = String(temperature);
  statusjson["lightlevel"] = String(lightlevel);
  statusjson["trigger"] = String(trigger);
  serializeJson(statusjson, Serial1);
}


//serial port from nodemcu
void mcuserial() {
  if (Serial1.available()){
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
