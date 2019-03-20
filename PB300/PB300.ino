
#include "pbduino.h"

Pb300 pb300; // Déclaration de ma maquette PB100

void setup() {
  Serial.begin(9600);
  Serial.print("PIERRON - PB300");
  pb100.init();
}

void loop() {
  //TODO!!!
    delay(500);
}
