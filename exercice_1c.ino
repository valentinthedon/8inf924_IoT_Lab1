const int ledPin = LED_BUILTIN;
const int buttonPin = 1;

void setup() {
 pinMode(buttonPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

void loop() {
  int val = digitalRead(buttonPin);

  if (val == HIGH) {  
    digitalWrite(ledPin, LOW);  
  } else {
    digitalWrite(ledPin, HIGH);
  }    
}
