#include <allegro.h>
#include "World.h"
#include "Player.h"

// TIMER
////////
volatile long speed = 0;
const int fps = 100;
int frame = 0;
void increment_speed() { speed++; }
END_OF_FUNCTION(increment_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);



int main(int argc, char *argv[])
{
    Player* player1 = new Player();

    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, World::screen_w, World::screen_h, 0, 0); //_WINDOWED
    install_keyboard();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(fps));


    World world;

    BITMAP *background = create_bitmap (World::map_w, World::map_h);
    BITMAP *buffer = create_bitmap (World::map_w, World::map_h);
    world.load_bitmap();
    player1->load_bitmap();

    while (!key[KEY_ESC])
    {
        while(speed > 0)
        {
			speed--;
            frame++;
            if (frame > 100) frame = 0;
		}

        world.draw (buffer, player1);
        player1->draw (buffer, frame);
        player1->check_key();
        player1->update();
        world.display_info(buffer, player1, frame);
        blit(buffer, screen, 0,0,0,0, World::map_w, World::map_h);
        //rest(1);
    }

    player1->delete_bitmap();
    world.delete_bitmap();
    destroy_bitmap(buffer);
    destroy_bitmap(background);

    delete player1;


    remove_int (increment_speed);
    allegro_exit();

    return 0;
}
END_OF_MAIN();
