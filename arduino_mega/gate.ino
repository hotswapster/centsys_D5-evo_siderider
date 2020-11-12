void gatecontrol() {
  
}




void gateinputs() {
  //beam block behaviour
  if (bb_pin == HIGH){
    beamblock = true;
  } else {
    beamblock = false;
  }

  //gate closed behaviour
  if (gc_pin == true) {
    gateclosed = true;
  } else {
    gateclosed = false;
  }

  //gate open behaviour
  if(go_pin == HIGH) {
    gateopen = true;
  } else {
    gateopen = false;
  }

}

void statusdecode() {
  
}
