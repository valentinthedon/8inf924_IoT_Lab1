#define INTERVAL 2000

void setup() {
  // LED_BUILTIN : alias du pin de la led intégré
    pinMode(LED_BUILTIN, OUTPUT);   // Connexion au pin en mode sortie
}
 
void loop() {
  digitalWrite(LED_BUILTIN,HIGH); // Allumage de la LED
  tempo(INTERVAL);                // On attends
  digitalWrite(LED_BUILTIN, LOW); // On éteint la LED
  tempo(INTERVAL);                // On attends a nouveau avant de recommencer
}

void tempo(int duree){
  int now = millis();       
  while(millis() < now + duree){
    // On attends, mais nous pourrions faire autre chose
  }
}