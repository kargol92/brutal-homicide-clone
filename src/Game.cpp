#include "Game.h"

extern volatile long speed;
extern const int fps;
extern int frame;

void Game::run()
{
    init();

    world;
    player1;
    world.load_bitmap();
    player1.load_bitmap();

    while (!key[KEY_ESC])
    {
        while (speed > 0)
        {
			speed--;
            frame++;
            if (frame > 100) frame = 0;
		}

        world.draw (buffer, player1);
        player1.draw (buffer, frame);
        player1.check_key();
        player1.update();
        world.display_info(buffer, player1, frame);
        blit(buffer, screen, 0, 0, 0, 0, World::map_w, World::map_h);
        //rest(1);
    }

    player1.delete_bitmap();
    world.delete_bitmap();

    exit();
}
