#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include <allegro.h>

class Game_loop
{
    public:
        virtual void run() = 0;

    protected:
        int width = 640;
        int height = 480;
        BITMAP *background;
        BITMAP *buffer;

        void init();
        void exit();
};

#endif // GAME_LOOP_H
