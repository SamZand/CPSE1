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
constexpr auto circleklein_sin(int degrees){
	return 32 + scaled_sine_from_degrees( degrees, 20);
}

constexpr auto circleklein_cos(int degrees){
	return 64 + scaled_cosine_from_degrees( degrees, 20);
}

constexpr auto circlegroot_sin(int degrees){
	return 32 + scaled_sine_from_degrees( degrees, 30);
}

constexpr auto circlegroot_cos(int degrees){
	return 64 + scaled_cosine_from_degrees( degrees, 30);
}

void tikken(auto &oled, auto middenpunt, 
					auto cos_klein, auto cos_groot, auto sin_klein, auto sin_groot){
	int uur = 0;
	int minuut = 0;
		
	for(;;){
		hwlib::wait_ms(200);
		oled.clear();
		minuut += 6;
		if(minuut == 360){
		minuut = 0;}
		
		hwlib::line( 
		middenpunt, 
		hwlib::location(
		cos_klein.get(uur*30), 
		sin_klein.get(uur*30))
		).draw( oled );   

		hwlib::line( 
		middenpunt, 
		hwlib::location(
		cos_groot.get(minuut), 
		sin_groot.get(minuut))
	  ).draw( oled );
	  }
		oled.flush();
}
int main(void)
{
    // kill the watchdog & wait for the PC console to start
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    auto scl 		= target::pin_oc(target::pins::scl);
    auto sda 		= target::pin_oc(target::pins::sda);
    auto i2c_bus 	= hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    auto oled 		= hwlib::glcd_oled_buffered(i2c_bus, 0x3c);
    auto middenpunt = hwlib::location(64, 32);
	auto sin_klein 	= lookup<360, int>(circleklein_sin);
	auto cos_klein 	= lookup<360, int>(circleklein_cos);
	auto sin_groot 	= lookup<360, int>(circlegroot_sin);
	auto cos_groot 	= lookup<360, int>(circlegroot_cos);

    oled.clear();
    hwlib::circle(oled.size / 2, square(oled.size).x / 20).draw(oled);
    oled.write(hwlib::location(64, 32));
	
    for(int uren = 0; uren < 360; uren += 6) {
		oled.write(hwlib::location(
		cos_groot.get(uren), 
		sin_groot.get(uren))); 
    }
	
	  for(int uren = 0; uren < 360; uren += 30) {
		oled.write(hwlib::location(
		cos_klein.get(uren), 
		sin_klein.get(uren))); 
	  }
	tikken(oled, middenpunt, cos_klein, cos_groot, sin_klein, sin_groot);
    oled.flush();
}
	