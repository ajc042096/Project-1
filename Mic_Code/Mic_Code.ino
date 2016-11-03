const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to


int Level = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  analogReference(DEFAULT);
}

void loop() {
  // read the analog in value:
  Level = analogRead(analogInPin); 
  
  Serial.print(Level);
  Serial.print("\n");

  delay(2);
}
