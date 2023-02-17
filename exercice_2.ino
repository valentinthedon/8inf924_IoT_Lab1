const int gasSensorPin = A1;                // Pin du capteur (A pour un pin analogique)
const int motorPin = 1;                     // Pin du ventilateur

int gasSensorVal = 0;                       // D'eclaration de la valeur du capteur de gaz

void setup() {
 Serial.begin(9600);                        // D'emmarage de l'interface d'affichade avec un baudrate de 9600
}

void loop() {
  gasSensorVal = analogRead(gasSensorPin);  // On lit la valeur du capteur de gaz
  Serial.println(gasSensorVal);             // On l'affiche sur la sortie
  // Si la présence de gaz dépasse un certain seuil alors on démarre le ventilateur
  if(gasSensorVal > 400) {
    // la vitesse est le second paramètre, est doit etre compris entre 0 et 255
    analogWrite(motorPin, 255);             // On demarre le moteur vittesse maximale
  }
  else {
    // plus de gaz dans l'air
    analogWrite(motorPin, 0);               // On eteint le ventilateur
  }
}
