
int shortcycletime = 10000; //10 second cycle
unsigned long tenseclast = millis();

void tensec() {
  if (millis() - tenseclast > shortcycletime) {           //run at intervel defined by tempcycletime
  fullstatusrequest(); 
  tenseclast = millis();
}
}
