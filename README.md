<!--

2019-03-20: create.

Licence: CeCill (http://www.cecill.info/)

Author: fthome
Email: fthome@pierron.fr

-->

# Pbduino Bibliothèque

Il s'agit d'une bibliothèque pour aider à la programmation des maquettes Arduino™ PB100, PB200 et PB300.
Ces maquettes à base d'Arduino™ Nano sont commercialisées par la société PIERRON - ASCO & CELDA (https://www.pierron.fr/)
en collaboration avec Patrice BUFFET, qui en a conçu le principe et développé la pédagogie.

Pour la version protype cette bibliothèque est livrée avec un fork de LiquidCrystal_I2C.

## Installation

Copier le dossier dans le repertoire Librairies du programme Arduino™.

## Exemple

  #include "pbduino.h"
  float distance;
  Pb100 pb100;

  void setup() {
    pb100.init();
  }

  void loop() {

    distance = pb100.distance();
    if (distance ==0){
      pb100.lcd().setCursor(0,1);
      pb100.lcd().print("Distance: ???   "); //Syntaxe qui permet d'utiliser toutes les méthodes de LiquidCristal
    }else{
      pb100.affiche("Distance: " + String(distance,0) + "mm ",1); //Syntaxe simplifiée
    }
    if (distance > 100){
      pb100.allume_led_verte();
      pb100.eteint_led_rouge();
      pb100.noBuzzer();
    }else if (distance != 0){
      pb100.allume_led_rouge();
      pb100.eteint_led_verte();
      pb100.buzzer();
    }
      delay(500);
  }
