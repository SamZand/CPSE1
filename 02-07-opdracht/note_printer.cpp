#include "hwlib.hpp"
#include "note_printer.hpp"

void note_printer::play(const note &n)
{
   if (n.frequency != 0)
   {
      hwlib::cout << "Frequency: " << n.frequency << " Duration: " << n.duration << hwlib::endl;
   }
}