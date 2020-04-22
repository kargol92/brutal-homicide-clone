#ifndef WORLD_H
#define WORLD_H
#include <allegro.h>
#include "Player.h"

class World
{
public:
    BITMAP *tiles;
    // _w - width in pixels _h - height in pixels
    // _W - width in tiles _H - height in tiles
    // _x - X coords in pixels _y - Y coords in pixels
    // _X - X coords in tiles _Y - Y coords in tiles
    static const int tile_w = 32;
    static const int tile_h = 32;
    static const int screen_w = 640;
    static const int screen_h = 480;
    static const int screen_W = screen_w / tile_w; //20 (640x480)
    static const int screen_H = screen_h / tile_h; //15 (640x480)
    static const int map_W = 40;
    static const int map_H = 30;
    static const int map_w = map_W * tile_w; //1280 (40x30)
    static const int map_h = map_H * tile_h; //960 (40x30)
//    static int scroll_x;
//    static int scroll_y;

    bool ammo_2x3 = false;
    bool grenade_2x4 = false;
    bool grenade_3x3 = false;
    bool grenade_3x4 = false;
    bool first_aid_3x1 = false;

//    unsigned char map[map_H][map_W] =
//    {
//        {100,100,100,100,100,100,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200},
//        {100, 0 , 0 , 0 , 0 ,120, 0 , 0 , 0 , 0 , 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {100,200,200, 1 , 2 ,100,200,200,200,200, 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {100, 3 ,200, 2 , 2 ,100,200, 0 , 0 ,200, 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {100, 0 , 0 , 0 , 0 ,200, 0 , 0 , 0 ,200, 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {100,110,100,100,110,100,200,200,200,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200, 0 , 0 , 0 , 0 ,200, 0 , 0 , 0 , 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200,200,200, 0 ,200,200,200,200,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200, 0 , 0 , 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200,200,200,200,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200, 0 ,200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//        {200, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
//    };

    //World();
    void load_bitmap();
    void draw(BITMAP* &buffer, Player* &player);
    void delete_bitmap();
    void display_info(BITMAP* &buffer, Player* player1, int frame);
};

#endif
