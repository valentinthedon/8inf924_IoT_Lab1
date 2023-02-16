// constants won't change. They're used here to set pin number
const int gasSensorPin = A1;    // the number of the LED pin
const int motorPin = 1;    // the number of the LED pin

// variables will change:
int gasSensorVal = 0;

void setup() {
 Serial.begin(9600);  
}

void loop() {
  gasSensorVal = analogRead(gasSensorPin); 
  
  Serial.println(gasSensorVal);
  
  if(gasSensorVal > 400) {
    analogWrite(motorPin, 250);    
  }
  else {
    analogWrite(motorPin, 0);
  }
      
}
