#ifndef PLAYER_H
#define PLAYER_H
#include <allegro.h>

class Player
{
public:
    enum direction_enum
    {
        up = 1,
        up_right = 2,
        right = 3,
        right_down = 4,
        down = 5,
        down_left = 6,
        left = 7,
        left_up = 8
    };

    char direction = up;
    enum edge_enum {up_edge = 1, right_edge = 3, down_edge = 5, left_edge = 7};
    char edge = up_edge;
    char edge_collision;

    BITMAP *bitmap;
    const int width = 14; //20
    const int height = 18; //18
    int map_X;
    int map_Y;
    int map_X1;
    int map_Y1;
    int map_x = 40;
    int map_y = 40;
    int map_x1 = map_x + width;
    int map_y1 = map_y + height;
    int screen_x = 40;
    int screen_y = 40;
    int scroll_x = 0;
    int scroll_y = 0;
    bool move = false;
    int add = 1;
    bool collision = false;

    int ammo = 0;
    int grenades = 0;
    int energy = 0;
    int lives = 0;
    int money = 0;
    int weapon = 0;

    void load_bitmap();
    void draw_bitmap(BITMAP* &buffer);
    void delete_bitmap();

    void check_key();
    void go_up();
    void go_down();
    void go_left();
    void go_right();
    void calculate_coords_and_stuff();
};

#endif
