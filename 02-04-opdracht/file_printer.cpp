#include "hwlib.hpp"
#include "file_printer.hpp"

void file_printer::file_setup()
{
    hwlib::cout << "File setup" << hwlib::endl;

    outfile.open("melody.cpp");
    outfile << "#include \"melody.hpp\"\n\n";
    outfile << "class generated_melody : public melody {\n";
    outfile << "public:\n";
    outfile << "   void play( note_player & p ){\n";
    outfile.close();
}

void file_printer::file_close()
{
    hwlib::cout << "File close" << hwlib::endl;

    outfile.open("melody.cpp", std::ofstream::app);
    outfile << "  }\n";
    outfile << "};";
    outfile.close();
}

void file_printer::play(const note &n)
{
    if (playing)
    {
        hwlib::cout << "Call setup" << hwlib::endl;
        file_setup();
        playing = false;
    }
    outfile.open("melody.cpp", std::ofstream::app);
    outfile << "    p.play( note{ " << n.frequency << " , " << n.duration << " } );\n";
    outfile.close();
}