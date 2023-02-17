#define INTERVAL 2000
void setup() {

  // Connexion au PIN de la LED integré au micro controleur
  pinMode(LED_BUILTIN, OUTPUT);
}
 
// La fonction delay attends une durée en bloquant le processus dans son entiereté (processus vital y compris),
// tempo utilise millis() qui recupere le temps depuis le démarrage du programme
void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  tempo(INTERVAL);
  digitalWrite(LED_BUILTIN, LOW);
  tempo(INTERVAL);
}


void tempo(int duree){
  int now = millis();
  while(millis()<now + time){
    // waiting
  }
}