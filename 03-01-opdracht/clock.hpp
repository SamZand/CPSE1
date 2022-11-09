#ifndef _OLEDCLOCK_HPP
#define _OLEDCLOCK_HPP
#include "hwlib.hpp"
#include "lookup.hpp"

class clock {
private:
  hwlib::glcd_oled &display;
  hwlib::target::pin_in &uurKnop;
  hwlib::target::pin_in &minuutKnop;
  const cos_lookup &coss;
  const sin_lookup &sins;
  int uur = 0;
  int minuut = 0;
  int seconden = 0;
  unsigned int verlopenTijd = 1;

  void tekenArm(int position, int length);
  void tekenNummers();
  void draw();

public:
  clock(hwlib::glcd_oled &display, hwlib::target::pin_in &uurKnop,
        hwlib::target::pin_in &minuutKnop, const cos_lookup &coss,
        const sin_lookup &sins)
      : display(display), uurKnop(uurKnop), minuutKnop(minuutKnop), coss(coss),
        sins(sins) {}

  void run();
};
#endif