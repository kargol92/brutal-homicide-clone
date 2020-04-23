#include "Game_loop.h"

void Game_loop::init()
{
    background = create_bitmap (width, height);
    buffer = create_bitmap (width, height);
}
void Game_loop::exit()
{
    destroy_bitmap(buffer);
    destroy_bitmap(background);
}
