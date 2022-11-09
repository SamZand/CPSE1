#include "clock.hpp"

void clock::run() {
  auto time = hwlib::now_us();

  if (minuutKnop.read()) {
    minuut++;
  }
  if (uurKnop.read()) {
    uur += 5;
  }
  hwlib::wait_ms(100);
  draw();

  if (time >= verlopenTijd * 1000000) {
    verlopenTijd++;
    seconden++;
  }
  if (seconden >= 60) {
    seconden = 0;
    minuut++;
  }
  if (minuut >= 60) {
    minuut = 0;
    uur += 5;
  }
  if (uur >= 60) {
    uur = 0;
  }
}

void clock::draw() {
  display.clear();
  tekenNummers();
  tekenArm(uur, 15);
  tekenArm(minuut, 24);
  tekenArm(seconden, 29);
  display.flush();
}

void clock::tekenArm(int position, int length) {
  hwlib::line(hwlib::xy(64, 32), hwlib::xy(64 + coss.get(position) * length,
                                           32 + sins.get(position) * length))
      .draw(display);
};

void clock::tekenNummers() {
  for (int i = 0; i < 60; i += 5) {
    if (i % 15 == 0) {
      hwlib::circle(hwlib::xy(64 + coss.get(i) * 28, 32 + sins.get(i) * 28), 2)
          .draw(display);
    } else {
      hwlib::circle(hwlib::xy(64 + coss.get(i) * 28, 32 + sins.get(i) * 28), 1)
          .draw(display);
    }
  }
}
