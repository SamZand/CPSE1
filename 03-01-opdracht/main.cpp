#include "clock.hpp"
#include "hwlib.hpp"
#include "lookup.hpp"

int main(void) {

  namespace target = hwlib::target;

  auto scl = target::pin_oc(target::pins::scl);
  auto sda = target::pin_oc(target::pins::sda);
  auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
  auto display = hwlib::glcd_oled(i2c_bus, 0x3c);
  display.clear();

  auto uurKnop = hwlib::target::pin_in(hwlib::target::pins::d2);
  auto minuutKnop = hwlib::target::pin_in(hwlib::target::pins::d3);

  constexpr cos_lookup coss;
  constexpr sin_lookup sins;

  auto klok = clock(display, uurKnop, minuutKnop, coss, sins);

  for (;;) {
    klok.run();
  }
}
