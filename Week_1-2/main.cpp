#include "hwlib.hpp"
#include "player.hpp"
#include "lsp_player.hpp"

// ===========================================================================
//
// main: play an rtttl string
//
// ===========================================================================

void playsong(player& p);

int main(void)
{

    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    // wait for the PC console to start
    hwlib::wait_ms(500);

    auto lsp = target::pin_out(target::pins::d7);
    auto p = lsp_player(lsp);
    playsong(p);
}
