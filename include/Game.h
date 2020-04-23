#ifndef GAME_H
#define GAME_H
#include <allegro.h>
#include <Game_loop.h>
#include "World.h"
#include "Player.h"

class Game : public Game_loop
{
    public:
        void run();

    private:
        World world;
        Player player1;

};

#endif // GAME_H
