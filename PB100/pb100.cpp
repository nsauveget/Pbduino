#include <stdarg.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "pb100.h"

/////////////////
//CONSTRUCTEURS//
/////////////////

Pb100::Pb100(){
  _pin_led_verte = 3;
  _pin_led_rouge = 4;
  _pin_buzzer = 2;
  _pin_trigger = 8;
  _pin_echo = 9;
  _lcd_i2c_addr = 0x20;
  _Pb100();
}

Pb100::Pb100(int pin_led_verte, int pin_led_rouge, int pin_buzzer, int pin_trigger, int pin_echo, int lcd_i2c_addr){
  _pin_led_verte = pin_led_verte;
  _pin_led_rouge = pin_led_rouge;
  _pin_buzzer = pin_buzzer;
  _pin_trigger = pin_trigger;
  _pin_echo = pin_echo;
  _lcd_i2c_addr = lcd_i2c_addr;
  _Pb100();
}
// Initialisation de la carte
void Pb100::_Pb100(){
  _tone_frequency = 0;
  pinMode(_pin_led_verte, OUTPUT);
  pinMode(_pin_led_rouge, OUTPUT);
  pinMode(_pin_buzzer, OUTPUT);
  pinMode(_pin_trigger, OUTPUT);
  digitalWrite(_pin_trigger, LOW);
  pinMode(_pin_echo, INPUT);
}

/////////////////
// LES LEDS    //
/////////////////

// Definit l'etat de la led verte LOW | HIGH
void Pb100::set_led_verte(uint8_t state) const{
  digitalWrite(_pin_led_verte, state);
}
// Allume la led verte
void Pb100::allume_led_verte() const{
  digitalWrite(_pin_led_verte, HIGH);
}
// Eteint la led verte
void Pb100::eteint_led_verte() const{
  digitalWrite(_pin_led_verte, LOW);
}
// Definit l'etat de la led rouge LOW | HIGH
void Pb100::set_led_rouge(uint8_t state) const{
  digitalWrite(_pin_led_rouge, state);
}
// Allume la led rouge
void Pb100::allume_led_rouge() const{
  digitalWrite(_pin_led_rouge, HIGH);
}
// Eteint la led rouge
void Pb100::eteint_led_rouge() const{
  digitalWrite(_pin_led_rouge, LOW);
}

/////////////////
// LE BUZZER   //
/////////////////

// Joue un son selon une frequence
void Pb100::buzzer(unsigned int frequency){
  _tone_frequency = frequency;
  tone(_pin_buzzer, frequency);
}
//  Joue un son selon une frequence pendant une durée
void Pb100::buzzer(unsigned int frequency, unsigned long duration){
  _tone_frequency = frequency;
  tone(_pin_buzzer, frequency, duration);
}
// Joue le meme son que precedement
void Pb100::buzzer() const{
  if (_tone_frequency>0){
    tone(_pin_buzzer, _tone_frequency);
  }
}
// Un peu de silence!
void Pb100::noBuzzer()const{
  noTone(_pin_buzzer);
  //TODO, si play, stopper
}
/*
// Jour une liste de notes, indéfiniment
void Pb100::play(int n, ...) const{
  va_list va;
  va_start (va, n);
  va_end(va);
  //TODO : un timer qui change les frequences
}
*/

////////////////
// HC-SR04    //
////////////////

// Mesure la distance ou 0 si echec
float Pb100::mesure() const{
  //Déclenche le trigger
  digitalWrite(_pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pin_trigger, LOW);
  return pulseIn(_pin_echo, HIGH, TIMEOUT) / 2.0 * VITESSE_DU_SON;
}
