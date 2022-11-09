#ifndef _NOTE_PRINTER_HPP
#define _NOTE_PRINTER_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note printer to print notes to the console
//
// ===========================================================================

class note_printer : public note_player
{
private:
public:
   note_printer() {}

   void play(const note &n) override;
};

#endif
