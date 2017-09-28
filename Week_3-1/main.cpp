#include "hwlib.hpp"
#include <algorithm>
#include "math_fun.hpp"

namespace target = hwlib::target;

namespace hwlib
{
constexpr location operator/(const location& lhs, int rhs)
{
    return location(lhs.x / rhs, lhs.y / rhs);
}
}

constexpr hwlib::location square(const hwlib::location& lhs)
{
    auto m = std::min(lhs.x, lhs.y);
    return hwlib::location(m, m);
}

constexpr void klok(auto oled, auto middenpunt)
{
    for(int angle_degrees = 0; angle_degrees < 360; angle_degrees += 30) {
	hwlib::circle(hwlib::location(
	(middenpunt.x + scaled_sine_from_degrees(angle_degrees, 30)),
	(middenpunt.y + scaled_cosine_from_degrees(angle_degrees, 30))
	),1).draw(oled);
    }
}

int main(void)
{

    // kill the watchdog & wait for the PC console to start
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    auto scl = target::pin_oc(target::pins::scl);
    auto sda = target::pin_oc(target::pins::sda);
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    auto oled = hwlib::glcd_oled_buffered(i2c_bus, 0x3c);
    auto middenpunt = hwlib::location(64, 32);

    oled.clear();
    hwlib::circle(oled.size / 2, square(oled.size).x / 20).draw(oled);
    oled.flush();
    klok(oled, middenpunt);
}