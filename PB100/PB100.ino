//#include <LCD.h>
//#include <Wire.h>
#include "pb100.h"

float mesure;

// Déclaration de ma maquette PB100
Pb100 pb100;

void setup() {
  Serial.begin(115200);
  pb100.buzzer(440);
  delay(500);
  pb100.noBuzzer();
}

void loop() {

  mesure = pb100.mesure();
  Serial.println("Mesure : " + String(mesure,4) + "mm");

  if (mesure > 100){
    pb100.allume_led_verte();
    pb100.eteint_led_rouge();
    pb100.noBuzzer();
  }else if (mesure != 0){
    pb100.allume_led_rouge();
    pb100.eteint_led_verte();
    pb100.buzzer();
  }
    delay(500);
}
