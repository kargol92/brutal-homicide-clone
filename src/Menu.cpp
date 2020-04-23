#include "Menu.h"

extern volatile long speed;
extern const int fps;
extern int frame;

void Menu::run()
{
    while (!key[KEY_ESC])
    {
        while (speed > 0)
        {
			speed--;
            frame++;
            if (frame > 100) frame = 0;
		}

        //textprintf_ex (buffer, font, 440,  5, makecol (255, 255, 128), -1, "Press enter");
        blit(buffer, screen, 0,0,0,0, 640, 480);
        check_key();
        //rest(1);
    }
}

void Menu::check_key()
{
    if (key[KEY_UP])
	{
        //go_up();
    }
    if (key[KEY_DOWN])
    {
        //go_down();
    }
    if (key[KEY_ENTER])
	{
        Game game;
        game.run();
    }
}
