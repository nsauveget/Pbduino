
#include "pbduino.h"

Pb200 pb200; // Déclaration de ma maquette PB100

void setup() {
  Serial.begin(9600);
  Serial.print("PIERRON - PB200");
  pb200.init();
}

void loop() {
  if (pb200.get_bouton_vert()==HIGH){
    pb200.buzzer(440); //La
    pb200.allume_led_verte();
    pb200.eteint_led_bleu();
    pb200.eteint_led_jaune();
    pb200.eteint_led_rouge();
  }else if (pb200.get_bouton_bleu()==HIGH){
    pb200.buzzer(392); //Sol
    pb200.eteint_led_verte();
    pb200.allume_led_bleu();
    pb200.eteint_led_jaune();
    pb200.eteint_led_rouge();
  }else if (pb200.get_bouton_rouge()==HIGH){
    pb200.buzzer(349); //Fa
    pb200.eteint_led_verte();
    pb200.eteint_led_bleu();
    pb200.eteint_led_jaune();
    pb200.allume_led_rouge();
  }else if (pb200.get_bouton_jaune()==HIGH){
    pb200.buzzer(330); //Mi
    pb200.eteint_led_verte();
    pb200.eteint_led_bleu();
    pb200.allume_led_jaune();
    pb200.eteint_led_rouge();
  }else{
    pb200.noBuzzer();
    pb200.eteint_led_verte();
    pb200.eteint_led_bleu();
    pb200.eteint_led_jaune();
    pb200.eteint_led_rouge();
  }

}
