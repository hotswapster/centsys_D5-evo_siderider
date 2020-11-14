
int shortcycletime = 10000; //10 second cycle
int shortercycletime = 2000; //10 second cycle
unsigned long tenseclast = millis();
unsigned long fiveseclast = millis();

void tensec() {
    if (millis() - tenseclast > shortcycletime) {           //run at intervel defined by tempcycletime
  
  fullstatusrequest(); 
  tenseclast = millis();
    } 
  }
  
void fivesec() {
    if (millis() - fiveseclast > shortercycletime) {           //run at intervel defined by tempcycletime
  
    light();
    fiveseclast = millis();
    }
}
