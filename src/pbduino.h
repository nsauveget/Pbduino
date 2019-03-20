/*
Une librairie pour piloter les modules didactiques PIERRON PB100, PB200, PB300 et suivants.
Il s'agit de modules pour Arduino nano débiés à l'éducation.

Développés et commercialisés par www.pierron.fr à partir d'idées originales de Patrice Buffet.

Auteur : fthome
*/

// Un peu de constantes (meme si pour la vitesse du son c'est discutable!)
#ifndef Pbduino_h
#define Pbduino_h

#include <stdarg.h>
#include "LiquidCrystal_I2C.h"
#include <Arduino.h>
//#include "property.h"

const unsigned long TIMEOUT = 25000;
const float VITESSE_DU_SON = 340.0 / 1000;



class Pbduino{
/*Une classe maitre avec les mécanismes communs à toutes les maquettes
    - gestion des LEDS
    - gestion du BUZZER
*/
  public :
  Pbduino();
  ~Pbduino();

  void set_led_verte(uint8_t state) const;
  void allume_led_verte() const;
  void eteint_led_verte() const;
  void set_led_rouge(uint8_t state) const;
  void allume_led_rouge() const;
  void eteint_led_rouge() const;
  void set_led_jaune(uint8_t state) const;
  void allume_led_jaune() const;
  void eteint_led_jaune() const;
  void set_led_bleu(uint8_t state) const;
  void allume_led_bleu() const;
  void eteint_led_bleu() const;

  void buzzer(unsigned int frequency);
  void buzzer(unsigned int frequency, unsigned long duration);
  void buzzer() const;
  void noBuzzer() const;
  //void playBuzzer(int n, ...) const;
  void init();

  protected :

  String _name;
  uint8_t _pin_led_verte;
  uint8_t _pin_led_rouge;
  uint8_t _pin_led_jaune;
  uint8_t _pin_led_bleu;

  uint8_t _pin_buzzer;
  unsigned int _tone_frequency;


};

class Pbduino_lcd : public Pbduino{
  /* Une sous classe de Pbduino pour les modules avec afficheur LCD
  */

  public :
  Pbduino_lcd();
  ~Pbduino_lcd();
  void init();
  LiquidCrystal_I2C lcd();
  void affiche(String txt);
  void affiche(String txt, int row);
  void affiche(String txt, int row, int col);

  protected :
  LiquidCrystal_I2C *_lcd;
  uint8_t _lcd_cols;
  uint8_t _lcd_rows;
};

class Pb100 : public Pbduino_lcd{
/*Une sous classe pour la maquette Pb100
elle contient :
  - une led verte
  - une led rouge
  - un buzzer
  - un module HC-SR04 pour mesurer une distance
  _ un afficheur LCD 16x2
*/

  public :
  Pb100();
  void init();
  float distance() const;

  private :
  void _Pb100();
  uint8_t _pin_trigger;
  uint8_t _pin_echo;
};

class Pb200 : public Pbduino{
/* Une sous classe pour la maquette Pb200
elle contient :
  - une led verte
  - une led rouge
  - une led jaune
  - une led bleu
  - un bouton vert
  - un bouton bleu
  - un bouton jaune
  - un bouton rouge
  - un buzzer
*/
  public :
  Pb200();
  int get_bouton_vert() const;
  int get_bouton_rouge() const;
  int get_bouton_bleu() const;
  int get_bouton_jaune() const;
  int get_bouton(uint8_t buton_no) const;

  private :
  void _Pb200();
  uint8_t _pin_bt_vert;
  uint8_t _pin_bt_rouge;
  uint8_t _pin_bt_jaune;
  uint8_t _pin_bt_bleu;
};

class Pb300 : public Pbduino_lcd{
  /* Une sous classe pour la maquette Pb300
  elle contient :
    - une led verte
    - une led rouge
    - un buzzer
    - deux leds blanches non pilotées
    - deux photoresistances branchées en diviseur de tension sur deux entrées analogiques
  */
  public :
  Pb300();
  void init();
  int get_photo1() const;
  int get_photo2() const;

  private :
  uint8_t _pin_photo_1;
  uint8_t _pin_photo_2;
  void _Pb300();
};
#endif
