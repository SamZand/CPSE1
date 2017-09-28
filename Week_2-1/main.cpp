#include "hwlib.hpp"
#include "message.hpp"

const char* text = "Hello world\n";

extern "C" void uart_put_char(char c)
{
    hwlib::cout << c;
}

extern "C" void print_asciz(const char* s);

void application()
{
    print_asciz(text);
}

int main(void)
{

    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    // wait for the PC console to start
    hwlib::wait_ms(500);

    application();

    // HWLIB_TRACE;
    // HWLIB_TRACE;
}