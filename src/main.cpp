#include <allegro.h>
#include "Menu.h"
#include "Game.h"

// TIMER
////////
volatile long speed = 0;
const int fps = 100;
int frame = 0;
void increment_speed() { speed++; }
END_OF_FUNCTION(increment_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);

void init_allegro();
void exit_allegro();

int main(int argc, char *argv[])
{
    init_allegro();

    //Menu menu;
    //menu.run();
    Game game;
    game.run();

    exit_allegro();

    return 0;
}
END_OF_MAIN();

void init_allegro()
{
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, World::screen_w, World::screen_h, 0, 0); //_WINDOWED
    install_keyboard();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(fps));
}

void exit_allegro()
{
    remove_int (increment_speed);
    allegro_exit();
}
