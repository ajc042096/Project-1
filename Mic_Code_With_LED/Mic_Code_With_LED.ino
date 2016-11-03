const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int Level = 0;        // value read from the pot
//int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop() {
  // read the analog in value:
  Level = analogRead(analogInPin);
  Level = Level + 100;
  
  
 
 
 //For LED Output
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  //Serial.print("Mic Level = ");
  Serial.print(Level);
  Serial.print("\n");


  //For LED Output
  //Serial.print("\t output = ");
 // Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
