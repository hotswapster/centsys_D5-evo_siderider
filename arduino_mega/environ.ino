



  //variables
  unsigned long newtime = millis();
  int tempcycletime = 10000; //temp read time in ms 500000 = 5 min



void environ() {
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
