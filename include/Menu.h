#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include "Game_loop.h"
#include "Game.h"

class Menu : public Game_loop
{
    public:
        void run();

    private:
        void check_key();
};

#endif // MENU_H
