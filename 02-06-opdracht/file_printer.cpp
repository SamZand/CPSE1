#include "file_printer.hpp"
#include "iostream"

void file_printer::file_setup()
{
    std::cout << "File setup" << std::endl;

    outfile.open("melody.cpp");
    outfile << "#include \"melody.hpp\"\n\n";
    outfile << "class generated_melody : public melody {\n";
    outfile << "public:\n";
    outfile << "   void play( note_player & p ){\n";
    outfile.close();
}

void file_printer::file_close()
{
    std::cout << "File close" << std::endl;

    outfile.open("melody.cpp", std::ofstream::app);
    outfile << "  }\n";
    outfile << "};";
    outfile.close();
}

void file_printer::play(const note &n)
{
    if (playing)
    {
        std::cout << "Call setup" << std::endl;
        file_setup();
        playing = false;
    }
    outfile.open("melody.cpp", std::ofstream::app);
    outfile << "    p.play( note{ " << n.frequency << " , " << n.duration << " } );\n";
    outfile.close();
}