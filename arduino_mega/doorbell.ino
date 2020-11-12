void doorbell() {
  unsigned long time = millis();
  if (ding_pin == HIGH) {
        time = millis();
        ding = true;
        if(millis()-time > dingdelay){     //Has time delay passed?
          ding = false;
 //         serial.print("Doorbell Pressed");
    }
  if (dong_pin == HIGH) {
        time = millis();
        dong = true;
        if(millis()-time > dongdelay){     //Has time delay passed?
          dong = false;
    }
   }
  }
 }
