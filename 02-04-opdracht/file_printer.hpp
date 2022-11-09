#ifndef _FILE_PRINTER_HPP
#define _FILE_PRINTER_HPP

#include "note_player.hpp"
#include "hwlib.hpp"
#include <fstream>

class file_printer : public note_player
{
private:
    bool playing = true;
    std::ofstream outfile;

public:
    file_printer() {}
    void play(const note &n) override;
    void file_setup();
    void file_close();
};

#endif