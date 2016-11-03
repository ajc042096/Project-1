// Example sketch for HTU21D humidity - temperature sensor

#include <Wire.h>
#include "cactus_io_HTU21D.h"

HTU21D htu;

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D Humidity - Temperature Sensor");
  Serial.println("RH\tTemp (C)\tTemp (F)\tHeat Index (C)\tHeat Index (F)");

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop() {
  
  htu.readSensor();
  
  Serial.print(htu.getHumidity()); Serial.print("%\t"); 
  Serial.print(htu.getTemperature_C()); Serial.print("*C\t\t"); 
  Serial.print(htu.getTemperature_F()); Serial.print("*F\t\t"); 
  Serial.print(htu.getHeatIndex_C()); Serial.print("*C\t\t");
  Serial.print(htu.getHeatIndex_F()); Serial.println("*F"); 
  
  delay(2000);
}
