
#include "pbduino.h"

// Déclaration des variables
float mesure;
Pb100 *pb100; // Déclaration de ma maquette PB100

void setup() {
  Serial.begin(9600);
  pb100 = new Pb100();
  Serial.print("PIERRON - PB100");
}

void loop() {

  mesure = pb100->mesure();
  Serial.println("Mesure : " + String(mesure,4) + "mm");
  
  pb100->lcd().println("Distance : " + String(mesure));
  if (mesure > 100){
    pb100->allume_led_verte();
    pb100->eteint_led_rouge();
    pb100->noBuzzer();
  }else if (mesure != 0){
    pb100->allume_led_rouge();
    pb100->eteint_led_verte();
    pb100->buzzer();
  }
    delay(500);
}
