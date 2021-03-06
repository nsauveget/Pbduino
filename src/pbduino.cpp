/*
Une librairie pour piloter les modules didactiques PIERRON PB100, PB200, PB300 et suivants.
Il s'agit de modules pour Arduino nano débiés à l'éducation.

Développés et commercialisés par www.pierron.fr à partir d'idées originales de Patrice Buffet.

Auteur : fthome
*/


#include "pbduino.h"

/*
********************   Classe Pbduino   ********************
*/


/*
CONSTRUCTEUR
*/
Pbduino::Pbduino():  _pin_led_verte(0), _pin_led_rouge(0), _pin_led_jaune(0), _pin_led_bleu(0), _pin_buzzer(0), _tone_frequency(440){
  //Serial.println("Creation Pbduino");
}

Pbduino::~Pbduino(){

}


void Pbduino::init(){
  //Initialisation des leds
  if (_pin_led_verte>0){
    pinMode(_pin_led_verte, OUTPUT);
  }
  if (_pin_led_rouge>0){
    pinMode(_pin_led_rouge, OUTPUT);
  }
  if (_pin_led_jaune>0){
    pinMode(_pin_led_jaune, OUTPUT);
  }
  if (_pin_led_bleu>0){
    pinMode(_pin_led_bleu, OUTPUT);
  }
  //Initialisation du buzzer
  if (_pin_buzzer>0){
    pinMode(_pin_buzzer, OUTPUT);
  }
}

/*
void Pbduino::init_lcd(uint8_t addr, uint8_t cols, uint8_t rows){
  _lcd = new LiquidCrystal_I2C(addr, cols, rows);
  _lcd->init()
  _lcd->backlight();
  _lcd->print("PIERRON");
  delay(1000);
}
*/

/////////////////
// LES LEDS    //
/////////////////

// Definit l'etat de la led verte LOW | HIGH
void Pbduino::set_led_verte(uint8_t state) const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, state);
  }
}
// Allume la led verte
void Pbduino::allume_led_verte() const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, HIGH);
  }
}
// Eteint la led verte
void Pbduino::eteint_led_verte() const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, LOW);
  }
}
// Definit l'etat de la led rouge LOW | HIGH
void Pbduino::set_led_rouge(uint8_t state) const{
  if (_pin_led_rouge >0){
    digitalWrite(_pin_led_rouge, state);
  }
}
// Allume la led rouge
void Pbduino::allume_led_rouge() const{
  if (_pin_led_rouge >0){
    digitalWrite(_pin_led_rouge, HIGH);
  }
}
// Eteint la led rouge
void Pbduino::eteint_led_rouge() const{
  if (_pin_led_rouge >0){
    digitalWrite(_pin_led_rouge, LOW);
  }
}
// Definit l'etat de la led jaune LOW | HIGH
void Pbduino::set_led_jaune(uint8_t state) const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, state);
  }
}
// Allume la led jaune
void Pbduino::allume_led_jaune() const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, HIGH);
  }
}
// Eteint la led jaune
void Pbduino::eteint_led_jaune() const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, LOW);
  }
}
// Definit l'etat de la led bleu LOW | HIGH
void Pbduino::set_led_bleu(uint8_t state) const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, state);
  }
}
// Allume la led bleu
void Pbduino::allume_led_bleu() const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, HIGH);
  }
}
// Eteint la led bleu
void Pbduino::eteint_led_bleu() const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, LOW);
  }
}

/////////////////
// LE BUZZER   //
/////////////////

// Joue un son selon une frequence
void Pbduino::buzzer(unsigned int frequency){
  if (_pin_buzzer > 0){
    _tone_frequency = frequency;
    tone(_pin_buzzer, frequency);
  }
}
//  Joue un son selon une frequence pendant une durée
void Pbduino::buzzer(unsigned int frequency, unsigned long duration){
  if (_pin_buzzer > 0){
    _tone_frequency = frequency;
    tone(_pin_buzzer, frequency, duration);
  }
}
// Joue le meme son que precedement
void Pbduino::buzzer() const{
  if (_pin_buzzer>0 &&_tone_frequency>0){
    tone(_pin_buzzer, _tone_frequency);
  }
}
// Un peu de silence!
void Pbduino::noBuzzer()const{
  if (_pin_buzzer > 0){
    noTone(_pin_buzzer);
  //TODO, si play, stopper
  }
}
/*
// Jour une liste de notes, indéfiniment
void Pb100::play(int n, ...) const{
  va_list va;
  va_start (va, n);
  va_end(va);
  //TODO : un timer qui change les frequences en 'tache de fond'
}
*/

/*
********************   Classe Pbduino_lcd   ********************
Une sous classe de Pbduino pour les modules avec afficheur LCD
*/

Pbduino_lcd::Pbduino_lcd(): Pbduino(), _lcd_cols(16), _lcd_rows(2){
}
Pbduino_lcd::~Pbduino_lcd(){
  delete _lcd;
}
void Pbduino_lcd::init(){
  Pbduino::init();
  _lcd = new LiquidCrystal_I2C(0x20,_lcd_cols,_lcd_rows);
  _lcd->init();
  delay(2000);
  _lcd->backlight();
  delay(500);
  _lcd->clear();
  delay(500);
  _lcd->setCursor(0,0);
  _lcd->print("PIERRON - " + _name);
  _lcd->setCursor(0,1);
}

LiquidCrystal_I2C Pbduino_lcd::lcd(){
  return *_lcd;
}

void Pbduino_lcd::affiche(String txt){
  affiche(txt, 0,0);
}
void Pbduino_lcd::affiche(String txt, int row){
  affiche(txt,row,0);
}
void Pbduino_lcd::affiche(String txt, int row, int col){
  while (txt.length()<_lcd_cols){
    txt += " ";
  }
  _lcd->setCursor(col, row);
  _lcd->print(txt);
}



/*
********************   Classe Pb100   ********************
Une sous classe pour la maquette Pb100
elle contient :
  - une led verte
  - une led rouge
  - un buzzer
  - un module HC-SR04 pour mesurer une distance
  _ un afficheur LCD 16x2
*/

Pb100::Pb100(): Pbduino_lcd(), _pin_trigger(8), _pin_echo(9){
  _pin_led_verte = 3;
  _pin_led_rouge = 4;
  _pin_buzzer=2;
  _name = "PB100";
}

void Pb100::init(){
  Pbduino_lcd::init();
  pinMode(_pin_trigger, OUTPUT);
  digitalWrite(_pin_trigger, LOW);
  pinMode(_pin_echo, INPUT);
}

// Mesure la distance ou 0 si echec
float Pb100::distance() const{
  //Déclenche le trigger
  digitalWrite(_pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pin_trigger, LOW);
  //Attend le retour du signal et renvoie la distance calculée
  return pulseIn(_pin_echo, HIGH, TIMEOUT) / 2.0 * VITESSE_DU_SON;
}


/*
********************   Classe Pb200   ********************
    Une sous classe pour la maquette Pb200
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

Pb200::Pb200(){
  _pin_led_verte = 4;
  _pin_led_rouge = 2;
  _pin_led_bleu = 5;
  _pin_led_jaune = 3;
  _pin_buzzer = 13;
  _pin_bt_bleu = 10;
  _pin_bt_vert = 9;
  _pin_bt_jaune = 12;
  _pin_bt_rouge = 11;
  _name = "PB200";
}

//void Pb200::init(){} Pas necessaire de surchager!

int Pb200::get_bouton_vert() const{
  return digitalRead(_pin_bt_vert);
}
int Pb200::get_bouton_rouge() const{
  return digitalRead(_pin_bt_rouge);
}
int Pb200::get_bouton_bleu() const{
  return digitalRead(_pin_bt_bleu);
}
int Pb200::get_bouton_jaune() const{
  return digitalRead(_pin_bt_jaune);
}
int Pb200::get_bouton(uint8_t buton_no) const{
  return digitalRead(_pin_bt_vert + buton_no); //Bof!
}

/*
********************   Classe Pb300   ********************

     Une sous classe pour la maquette Pb300
    elle contient :
      - une led verte
      - une led rouge
      - un buzzer
      - deux leds blanches non pilotées
      - deux photoresistances branchées en diviseur de tension sur deux entrées analogiques
*/

Pb300::Pb300():Pbduino_lcd(), _pin_photo_1(A0), _pin_photo_2(A1){
  _pin_led_verte = 2;
  _pin_led_rouge = 4;
  _pin_buzzer = 6;
  _name = "PB300";
  _lcd_cols = 20;
  _lcd_rows = 4;
}

void Pb300::init(){
  Pbduino_lcd::init();
  pinMode(_pin_photo_1, INPUT);
  pinMode(_pin_photo_2, INPUT);
}

int Pb300::get_photo1() const{
  return analogRead(_pin_photo_1);
}
int Pb300::get_photo2() const{
  return analogRead(_pin_photo_2);
}
