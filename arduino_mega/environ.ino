



  //variables
  unsigned long newtime = millis();
  int tempcycletime = 10000; //temp read time in ms 500000 = 5 min
  
  //light sensor -------------------ᐯ
  const double k = 5.0/1024;
  const double luxFactor = 500000;
  const double R2 = 10000;
  const double LowLightLimit = 200; 
  const double B = 1.3*pow(10.0,7);
  const double m = -1.4;
  const int LED = LED_BUILTIN; // dim LED as light intensity changes

  double light_intensity (int RawADC0) {  
    double V2 = k*RawADC0;
    double R1 = (5.0/V2 - 1)*R2;
    double lux = B*pow(R1,m);
    return lux;
    } 
  //light sensor -------------------ᐱ
    
void environ() {

  //temperature
  if (millis() - newtime > tempcycletime) {           //run at intervel defined by tempcycletime
    
  // Send the command for all devices on the bus to perform a temperature conversion:
  sensors.requestTemperatures();
  // Fetch the temperature in degrees Celsius for device index:
  float tempC = sensors.getTempCByIndex(0); // the index 0 refers to the first device
  temperature = tempC;                      // write temperature to a global
  // Print the temperature in Celsius in the Serial Monitor:
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");
  newtime = millis(); 
}


}

void light() {
    double intensity = light_intensity(analogRead(0));
    lightlevel = intensity;
  Serial.println(String("Light level is: " + String(intensity) + " lux, not calibrated"));  
}
