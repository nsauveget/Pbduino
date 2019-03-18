
const unsigned long TIMEOUT = 25000;
const float VITESSE_DU_SON = 340.0 / 1000;

class Pb100{

  public :

  Pb100();
  Pb100(int pin_led_verte, int pin_led_rouge, int pin_buzzer, int pin_trigger, int pin_echo, int lcd_i2c_addr);

  void set_led_verte(uint8_t state) const;
  void allume_led_verte() const;
  void eteint_led_verte() const;
  void set_led_rouge(uint8_t state) const;
  void allume_led_rouge() const;
  void eteint_led_rouge() const;

  void buzzer(unsigned int frequency);
  void buzzer(unsigned int frequency, unsigned long duration);
  void buzzer() const;
  void noBuzzer() const;
  //void playBuzzer(int n, ...) const;

  float mesure() const;

  private :

  void _Pb100();

  int _pin_led_verte;
  int _pin_led_rouge;
  int _pin_buzzer;
  int _pin_trigger;
  int _pin_echo;
  int _lcd_i2c_addr;
  unsigned int _tone_frequency;

};
