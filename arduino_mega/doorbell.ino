
// variables for doorbell
bool dingb4;
bool dongb4;

void doorbell() {


  //ding behaviour
  dingb4 = ding;
  ding = digitalRead(ding_pin); //read new value
    if (ding != dingb4){ //if value changes, do something
      if (ding == 0){Serial.println("Doorbell Pressed");}
    dingb4 = ding;
    } 

  //dong behaviour
  dongb4 = dong;
  dong = digitalRead(dong_pin); //read new value
  if (dong != dongb4){ //if value changes, do something
    if (dong == 0){Serial.println("Doorbell - Open Gate Pressed");}
    dongb4 = dong;
  } 
 }

 
