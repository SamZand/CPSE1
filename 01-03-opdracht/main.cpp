#include "hwlib.hpp"

extern "C" void print_asciz(const char *s);

extern "C" void application();

extern "C" void uart_put_char(char c)
{
    hwlib::cout << c;
}

extern "C" char toggle_case(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32; // Add 32 to convert uppercase character to a lowercase
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 32; // Substract 32 to convert lowercase character to an uppercase
    }
    else
    {   
        return c; // Return the character if it isn't a letter a-z or A-Z
    }
}

int main(void)
{

    namespace target = hwlib::target;

    // wait for the PC console to start
    hwlib::wait_ms(2000);

    application();
}