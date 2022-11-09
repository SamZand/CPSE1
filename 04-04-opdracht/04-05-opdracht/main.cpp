#include "hwlib.hpp"

#include <fstream>

extern "C" void decompress();

extern "C" void print_char(char c) { hwlib::cout << c; }

int main(void) {
  hwlib::wait_ms(1000);
  hwlib::cout << "Start:" << hwlib::endl;
  hwlib::wait_ms(1000);
  decompress();
  hwlib::cout << "Done!" << hwlib::endl;
}