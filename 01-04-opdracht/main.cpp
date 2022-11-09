#include "hwlib.hpp"

extern "C" void print_asciz(const char *s);

extern "C" void application();

extern "C" void uart_put_char(char c)
{
    hwlib::cout << c;
}

extern "C" char toggle_case(char c);

int main(void)
{

    namespace target = hwlib::target;

    // wait for the PC console to start
    hwlib::wait_ms(2000);

    application();
}