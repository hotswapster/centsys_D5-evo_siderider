

// using switch only allows one character sent from serial. Sending this character from monitor will triggger relay.
void myserial() {
  if (Serial.available()) {
    char ser = Serial.read();
//    Serial.println("received");
    switch(ser){ 
      case '1': lockposon(lockinpos_pin); break;
      case '2': lockposoff(lockinpos_pin); break;
      case '3': lockopenon(lockopen_pin); break;
      case '4': lockopenoff(lockopen_pin); break;
      case '5': triggeron(trig_pin); break;
      case '7': turnlighton(lights_pin); break;
      case '8': turnlightoff(lights_pin); break;
}
}
}
