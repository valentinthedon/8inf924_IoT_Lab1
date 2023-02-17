#define INTERVAL 2000               // intervalle de temps de switch on/off

void setup() {
    // LED_BUILTIN : alias du pin de la led intégré
    pinMode(LED_BUILTIN, OUTPUT);   // Connexion au pin en mode sortie
}

void loop() {
    digitalWrite(LED_BUILTIN,HIGH); // Allumage de la LED
    delay(INTERVAL);                // On attends
    digitalWrite(LED_BUILTIN, LOW); // On éteint la LED
    delay(INTERVAL);                // On attends a nouveau avant de recommencer
}