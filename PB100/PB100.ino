
#include "pbduino.h"

// Déclaration des variables
float distance;
Pb100 *pb100; // Déclaration de ma maquette PB100

void setup() {
  Serial.begin(9600);
  pb100 = new Pb100();
  Serial.print("PIERRON - PB100");
}

void loop() {

  distance = pb100->distance();
  Serial.println("Mesure : " + String(distance,4) + "mm");

  pb100->lcd().setCursor(0,1);
  if (distance ==0){
    pb100->lcd().print("Distance: ???   ");
  }else{
    pb100->lcd().print("Distance: " + String(distance,0) + "mm ");
  }
  if (distance > 100){
    pb100->allume_led_verte();
    pb100->eteint_led_rouge();
    pb100->noBuzzer();
  }else if (distance != 0){
    pb100->allume_led_rouge();
    pb100->eteint_led_verte();
    pb100->buzzer();
  }
    delay(500);
}
