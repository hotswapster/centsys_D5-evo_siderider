
int shortcycletime = 10000; //10 second cycle
int shortercycletime = 5000; //5 second cycle
int midcycletime = 30000; //30 sec cycle
unsigned long tenseclast = millis();
unsigned long fiveseclast = millis();
unsigned long thiseclast = millis();

void thirtysec() {
    if (millis() - thiseclast > midcycletime) {           //run at intervel defined by midcycletime
      //Put 30 second update calls here-------------ᐯ

    //  fullstatusrequesttomcu();
      
      //Put 30 second update calls here-------------ᐱ
      
      thiseclast = millis();
    } 
  }


void tensec() {
    if (millis() - tenseclast > shortcycletime) {           //run at intervel defined by shortcycletime
      //Put 10 second update calls here-------------ᐯ
      light();
      fullstatusrequest(); 
      
      //Put 10 second update calls here-------------ᐱ
      
      tenseclast = millis();
    } 
  }
  
void fivesec() {
    if (millis() - fiveseclast > shortercycletime) {           //run at intervel defined by shortercycletime
  //Put 5 second update calls here-------------ᐯ
    //mcuserial();
    
    //Print cycle time only every 5 seconds
    Serial.println(String("The cycle time was: " + String(cycletime) + "ms. The maximum cycle time since boot was: " + String(maxcycletime) + "ms"));

    
  //Put 5 second update calls here-------------ᐱ
    fiveseclast = millis();
    }
}
