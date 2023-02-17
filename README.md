# 8INF924 IoT - Laboratoire 1
## Introduction
Au sein de ce dépot vous trouverez l'ensemble des livrables du Laboratoire 1 du cours "8INF924 - Internet of Things" de l'UQAC. Ce projet a été réalisé par :
- Valentin THEDON - THEV10079801
- Samia CHAHBOUNIA - CHAS24580000

Dans ce README, nous répondrons à l'ensemble des questions du TP et expliciterons notre démarche.
## Environnemnt
### Hardware
- [Arduino MKR Wifi 1010](https://docs.arduino.cc/hardware/mkr-wifi-1010)
- [Module moteur/ventilateur](https://wiki.dfrobot.com/Gravity__130_DC_Motor_SKU__DFR0411)
- [Capteur de gaz](https://wiki.dfrobot.com/Analog_Gas_Sensor_MQ9__SKU_SEN0134) : permet de detecter différents gaz tel que le Monoxyde de Carbone, le méthane, le propane, etc. Ce capteur fonctionne grâce à la sensibilité du [dioxyde d'étain](https://fr.wikipedia.org/wiki/Dioxyde_d%27%C3%A9tain) à la présence de ces gazs dans l'air. En utilisant la lecture analogique, il nous est possible de récupérer la valeur du capteur, ici ce sont des ppm, qui mesure la pollution dans l'air. Pour les gaz combustibles (type méthane, propane, etc.) il peut capter jusqu'à 10 000 ppm.
- [Bouton poussoir](https://wiki.dfrobot.com/DFRobot_Digital_Push_Button_SKU_DFR0029) : fonctionne très simplement, comme le plus viez interrupteur du monde, conecte 2 plaques de cuivre qui laisse passe on non le courant.
### Software
Pour le dévellopement des logiciels embarqués dans le microcontrôleur, nous avons utilisé [Arduino IDE](https://wiki-content.arduino.cc/en/software)
## Exercice 1
### 1.1
Dans cette partie, nous avos simplement brancher le microcontrôleur à la machine et téléverser le programme `exercice_1a.ino`. Étant donné le manque de disponibilités de module LED, nous avons utilisé celle intégrée à l'Arduino, d'ou la présence dans le code de l'alias `LED_BUILTIN`. La fonction `delay()` nous permet de mettre en pause le programme. Dans notre cas cela évite un clignotement trop rapide qui serai invisible à l'oeil nu. (cf. `exercice_1a.ino`)
### 1.2
Pour la partie suivante, nous reprenons le même code que précedemment sauf que nous y apportons quelques modifications. En effet la fonction `delay()` est substituée par la fonction `tempo()` que nous avon rédigé.

`tempo()` réalise dans notre cas la même fonction que `delay()`, mettre en pause le programme. Cependant, cela nous permets de comprendre l'intérêt et la différence de la méthode `millis()`. En effet, cette dernière nous renvoie simplement le temps écoulé depuis le début de l'exécution, donc grâce à cela et un jeu de conditions, nous pouvons réalisé du code de manière cyclique avec un intervalle de temps régulier, sans forcément mettre en pause le reste du programme. (cf. `exercice_1b.ino`)
### 1.3
Pour cette partie d'exercice, nous utiliseron le bouton poussoir. Pour ce faire nous le relions le module au pin +5V et GND du microcontrôleur ainsi qu'au pin D1, ce qui nous permettra de communiquer et de recevoir son statut. 

Lorsque vous téléversez le programme sur la carte, si le bouton est préssé alors la LED intégré s'eteint, sinon elle restera alumé. (cf. `exercice_1c.ino`)

## Exercice 2
Les différents capteurs sélectionnés l'ont été pour un bonne raison. Le capteur de gaz nous recupère une grandeur (en ppm), lorsque cette valeur dépasse un seuil alors le ventilateur s'active afin d'evacuer l'air de la pièce. D'àpres quelques recherches sur Internet, le méthane ne devient dangereux qu'au dela de 50 000 ppm or notre capteur ne va que jusque 10 000 ppm, ce qui est parfait car il peut avoir un simple rôle de prévention et démarrer la ventilation d'une cuisine lorsque qu'il detecte du gaz. Cela pourrai être mis en amont d'une alarme pour rajouter une sécurité supplémentaire.

**NB :** Afin que le capteur soit totalement opérationnel et renvoie une valeur valide, il est nécéssaire de le faire chauffer (ce qui prends environ 45 secondes). Pour ne pas focément avoir l'activation du ventilateur durant le temps de chauffe, il pourrait être judicieux de placer un `delay()` au démarrage du programme. 
### Schéma de montage
![Schéma de montage](/schema.png "Schéma de montage")
### Vidéo de démonstration
Accessible via ce [lien](https://youtu.be/PYr5y6yWB10)
### Résultat
Après avoir réalisé quelques tests, nous remarquons l'efficacité du système. En effet, en faisant fonctionner le capteur seul, la durée pour repasser sous le seuil d'acceptabilité (dispersion naturelle du gaz dans l'air) est bien plus longue que celle du système avec le ventilateur.
## Références
- [MQ9 Gas Sensor](https://fr.wikipedia.org/wiki/Capteur_de_gaz_MQ-9)
- [Partie par million (ppm)](https://fr.wikipedia.org/wiki/Partie_par_million)