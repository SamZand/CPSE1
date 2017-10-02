#include "hwlib.hpp"
#include "math_fun.hpp"
#include <algorithm>

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

template <int N, typename T> class lookup
{
private:
    T values[N];

public:
    template <typename F> constexpr lookup(F function)
    {
	for(int i = 0; i < N; ++i) {
	    values[i] = function(i);
	}
    }
    constexpr T get(int n) const
    {
	return values[n];
    }
};
constexpr auto circleklein_sin(int degrees)
{
    return 32 + scaled_sine_from_degrees(degrees, 20);
}

constexpr auto circleklein_cos(int degrees)
{
    return 64 + scaled_cosine_from_degrees(degrees, 20);
}

constexpr auto circlegroot_sin(int degrees)
{
    return 32 + scaled_sine_from_degrees(degrees, 30);
}

constexpr auto circlegroot_cos(int degrees)
{
    return 64 + scaled_cosine_from_degrees(degrees, 30);
}

constexpr void layout(auto &oled)
{
    auto sin_klein = lookup<360, int>(circleklein_sin);
    auto cos_klein = lookup<360, int>(circleklein_cos);
    auto sin_groot = lookup<360, int>(circlegroot_sin);
    auto cos_groot = lookup<360, int>(circlegroot_cos);

    for(int minuten = 0; minuten < 360; minuten += 6) {
	oled.write(hwlib::location(cos_groot.get(minuten), sin_groot.get(minuten)));
    }

    for(int uren = 0; uren < 360; uren += 30) {
	oled.write(hwlib::location(cos_klein.get(uren), sin_klein.get(uren)));
    }
}

constexpr void tikken(auto& oled, auto middenpunt, auto sw0, auto sw1, auto sw2)
{

    auto sin_klein = lookup<360, int>(circleklein_sin);
    auto cos_klein = lookup<360, int>(circleklein_cos);
    auto sin_groot = lookup<360, int>(circlegroot_sin);
    auto cos_groot = lookup<360, int>(circlegroot_cos);
    int uur = 0;
    int minuut = 0;

    for(;;) {
	
	oled.clear();
	if(!sw0.get()) {
	    minuut += 1;
	    if(minuut >= 60) {
		minuut = 0;
		uur += 1;
	    }
	    if(uur >= 12) {
		uur = 0;
	    }
	}

	if(!sw1.get()) {
	    uur += 1;
	    if(uur >= 12) {
		uur = 0;
	    }
	}

	for(int minuten = 0; minuten < 360; minuten += 6) {
	    oled.write(hwlib::location(cos_groot.get(minuten), sin_groot.get(minuten)));
	}

	for(int uren = 0; uren < 360; uren += 30) {
	    oled.write(hwlib::location(cos_klein.get(uren), sin_klein.get(uren)));
	}

	minuut += 1;
	if(minuut >= 60) {
	    minuut = 0;
	    uur += 1;
	    if(uur >= 12) {
		uur = 0;
	    }
	}

	// hwlib::cout<< "minuut - "<< minuut << "\n" << "uur - " << uur << "\n";

	hwlib::line(middenpunt, hwlib::location(cos_klein.get(359 - (uur * 30)), sin_klein.get(359 - (uur * 30))))
	    .draw(oled);

	hwlib::line(middenpunt, hwlib::location(cos_groot.get(359 - (minuut * 6)), sin_groot.get(359 - (minuut * 6))))
	    .draw(oled);
	oled.flush();
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
    auto sw0 = target::pin_in(target::pins::d5);
    auto sw1 = target::pin_in(target::pins::d6);
    auto sw2 = target::pin_in(target::pins::d7);
	
	layout(oled);
    tikken(oled, middenpunt, sw0, sw1, sw2);
}
