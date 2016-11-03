const int ap1 = A0; 
const int ap2 = A1;
const int ap3 = A2;

int sv1 = 0;        
int ov1 = 0;    
int sv2 = 0;      
int ov2= 0;      
int sv3 = 0;       
int ov3= 0;    

const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to
int Level = 0;        // value read from the pot

#include <Wire.h>
#include "cactus_io_HTU21D.h"

HTU21D htu;
void setup() {

 //For Temperature Sensor
 Serial.begin(9600);
  Serial.println("HTU21D Humidity - Temperature Sensor");
  Serial.println("RH\tTemp (C)\tTemp (F)\tHeat Index (C)\tHeat Index (F)");

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
  
//For mic
 analogReference(DEFAULT);
}

void loop() {

//For Temperature sensor
 htu.readSensor();
  
  Serial.print(htu.getHumidity()); Serial.print("%\t"); 
  Serial.print(htu.getTemperature_C()); Serial.print("*C\t\t"); 
  Serial.print(htu.getTemperature_F()); Serial.print("*F\t\t"); 
  Serial.print(htu.getHeatIndex_C()); Serial.print("*C\t\t");
  Serial.print(htu.getHeatIndex_F()); Serial.println("*F"); 


//For Accelerometer
  analogReference(EXTERNAL);    //connect 3.3v to AREF
  // read the analog in value:
  sv1 = analogRead(ap1);            
  // map it to the range of the analog out:
  ov1 = map(sv1, 0, 1023, 0, 255);  
  // change the analog out value:
  delay(2);                     
  //
  sv2 = analogRead(ap2);            
  
  ov2 = map(sv2, 0, 1023, 0, 255); 
 // 
  delay(2);                 
  //
  sv3 = analogRead(ap3);            
  
  ov3 = map(sv3, 0, 1023, 0, 255);  
  
// print the results to the serial monitor:
  Serial.print("Xsensor1 = " );                       
  Serial.print(sv1);      
  Serial.print("\t output1 = ");      
  Serial.println(ov1);   
 
  Serial.print("Ysensor2 = " );                       
  Serial.print(sv2);      
  Serial.print("\t output2 = ");      
  Serial.println(ov2);   

  Serial.print("Zsensor3 = " );                       
  Serial.print(sv3);      
  Serial.print("\t output3 = ");      
  Serial.println(ov3);   

  Level = analogRead(analogInPin); 
  
  Serial.print(Level);
  Serial.print("\n");

  //Pause
 
  delay(2000);
}
