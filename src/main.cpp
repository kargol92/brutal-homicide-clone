#include <allegro.h>
#include "Map.h"

// TIMER
////////
volatile long speed = 0;
const int fps = 100;
int frame = 0;
void increment_speed() { speed++; }
END_OF_FUNCTION(increment_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);


#include "global_variables.h"
#include "map.h"
#include "World.h"
#include "Player.h"

World world;
Player player;


void display_map(BITMAP * & bg, BITMAP * & tiles);
void display_coords_and_stuff(BITMAP * & buffer);

//#include "check.h"
#include "display.h"

void init();
void run();
void exit();

int main(int argc, char *argv[])
{
    init();
    //CPlayer a;
    run();
    exit();
    return 0;
}
END_OF_MAIN();

void init()
{
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, World::screen_w, World::screen_h, 0, 0); //_WINDOWED
    install_keyboard();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(fps));
}

void run()
{
    BITMAP *buffer = create_bitmap (World::map_w, World::map_h);
    BITMAP *bg = create_bitmap (World::map_w, World::map_h);
    world.load_bitmap();
    player.load_bitmap();

    while (!key[KEY_ESC])
    {
        while(speed > 0)
        {
			speed--;
            frame++;
            if (frame > 100) frame = 0;
		}
		player.calculate_coords_and_stuff();
        player.check_key();
        display_map (buffer, world.tiles);
        player.draw_bitmap(buffer);
        display_coords_and_stuff(buffer);
        blit(buffer, screen, 0,0,0,0, World::map_w, World::map_h);
        //rest(1);
    }
    remove_int( increment_speed);
    destroy_bitmap(buffer);
    destroy_bitmap(bg);
    player.delete_bitmap();
    world.delete_bitmap();
}

void exit()
{
    allegro_exit();
}
