#include "Player.h"
#include "World.h"

extern World world;
extern int frame;

void Player::load_bitmap()
{
    bitmap = load_bmp ("graphics/player.bmp", default_palette);
}

void Player::draw_bitmap(BITMAP* &buffer)
{
	if (move == false)
	{
		if (direction == up)
            masked_blit(bitmap, buffer, 1,1, screen_x, screen_y, 23, 14);
        else if (direction == down)
            masked_blit(bitmap, buffer, 25,1, screen_x, screen_y, 23, 14);
        else if (direction == left)
            masked_blit(bitmap, buffer, 49,1, screen_x, screen_y, 14, 23);
        else if (direction == right)
            masked_blit(bitmap, buffer, 76,1, screen_x, screen_y, 14, 23);
	}
	else if (move == true)
    {
		if (direction == up)
		{
			if (frame < 20)
                masked_blit (bitmap, buffer, 1,1, screen_x, screen_y, 23, 14);
            else if (frame >= 20 && frame < 40)
                masked_blit (bitmap, buffer, 1,16, screen_x, screen_y, 20, 18);
            else if (frame >= 40 && frame < 60)
                masked_blit (bitmap, buffer, 1,35, screen_x, screen_y, 20, 24);
            else if (frame >= 60 && frame < 80)
                masked_blit (bitmap, buffer, 1,60, screen_x, screen_y, 20, 17);
            else if (frame >= 80 && frame < 100)
                masked_blit (bitmap, buffer, 1,80, screen_x, screen_y, 20, 20);
		}
		else if (direction == up_right)
		{
			if( frame<20) { masked_blit( bitmap, buffer, 1,1, screen_x, screen_y, 23, 14);}
            else if( frame>=20 && frame<40) { masked_blit( bitmap, buffer, 1,16, screen_x, screen_y, 20, 18);}
            else if( frame>=40 && frame<60) { masked_blit( bitmap, buffer, 1,35, screen_x, screen_y, 20, 24);}
            else if( frame>=60 && frame<80) { masked_blit( bitmap, buffer, 1,60, screen_x, screen_y, 20, 17);}
            else if( frame>=80 && frame<100) { masked_blit( bitmap, buffer, 1,80, screen_x, screen_y, 20, 20);}
		}
		else if (direction == right)
		{
			if( frame<20) {masked_blit( bitmap, buffer, 76,1, screen_x, screen_y, 14, 23);}
            else if( frame>=20 && frame<40) {masked_blit( bitmap, buffer, 76,25, screen_x, screen_y, 18, 20);}
        	else if( frame>=40 && frame<60) {masked_blit( bitmap, buffer, 76,46, screen_x, screen_y, 24, 20);}
            else if( frame>=60 && frame<80) {masked_blit( bitmap, buffer, 76,67, screen_x, screen_y, 17, 20);}
            else if( frame>=80 && frame<100) {masked_blit( bitmap, buffer, 76,88, screen_x, screen_y, 26, 20);}
		}
		else if (direction == right_down)
		{
			if( frame<20) {masked_blit( bitmap, buffer, 76,1, screen_x, screen_y, 14, 23);}
            else if( frame>=20 && frame<40) {masked_blit( bitmap, buffer, 76,25, screen_x, screen_y, 18, 20);}
        	else if( frame>=40 && frame<60) {masked_blit( bitmap, buffer, 76,46, screen_x, screen_y, 24, 20);}
            else if( frame>=60 && frame<80) {masked_blit( bitmap, buffer, 76,67, screen_x, screen_y, 17, 20);}
            else if( frame>=80 && frame<100) {masked_blit( bitmap, buffer, 76,88, screen_x, screen_y, 26, 20);}
		}
		else if (direction == down)
		{
			if( frame<20) { masked_blit( bitmap, buffer, 25,1, screen_x, screen_y, 23, 14);}
            else if( frame>=20 && frame<40) { masked_blit( bitmap, buffer, 25,16, screen_x, screen_y, 20, 18);}
            else if( frame>=40 && frame<60) { masked_blit( bitmap, buffer, 25,35, screen_x, screen_y, 20, 24);}
            else if( frame>=60 && frame<80) { masked_blit( bitmap, buffer, 25,60, screen_x, screen_y, 20, 17);}
            else if( frame>=80 && frame<100) { masked_blit( bitmap, buffer, 25,80, screen_x, screen_y, 20, 20);}
		}
		else if (direction == down_left)
		{
			if( frame<20) { masked_blit( bitmap, buffer, 25,1, screen_x, screen_y, 23, 14);}
            else if( frame>=20 && frame<40) { masked_blit( bitmap, buffer, 25,16, screen_x, screen_y, 20, 18);}
            else if( frame>=40 && frame<60) { masked_blit( bitmap, buffer, 25,35, screen_x, screen_y, 20, 24);}
            else if( frame>=60 && frame<80) { masked_blit( bitmap, buffer, 25,60, screen_x, screen_y, 20, 17);}
            else if( frame>=80 && frame<100) { masked_blit( bitmap, buffer, 25,80, screen_x, screen_y, 20, 20);}
		}
		else if (direction == left)
		{
			if( frame<20) {masked_blit( bitmap, buffer, 49,1, screen_x, screen_y, 14, 23);}
        	else if( frame>=20 && frame<40) {masked_blit( bitmap, buffer, 49,25, screen_x, screen_y, 18, 20);}
            else if( frame>=40 && frame<60) {masked_blit( bitmap, buffer, 49,46, screen_x, screen_y, 24, 20);}
            else if( frame>=60 && frame<80) {masked_blit( bitmap, buffer, 49,67, screen_x, screen_y, 17, 20);}
            else if( frame>=80 && frame<100) {masked_blit( bitmap, buffer, 49,88, screen_x, screen_y, 26, 20);}
		}
		else if (direction == left_up)
		{
			if( frame<20) {masked_blit( bitmap, buffer, 49,1, screen_x, screen_y, 14, 23);}
        	else if( frame>=20 && frame<40) {masked_blit( bitmap, buffer, 49,25, screen_x, screen_y, 18, 20);}
            else if( frame>=40 && frame<60) {masked_blit( bitmap, buffer, 49,46, screen_x, screen_y, 24, 20);}
            else if( frame>=60 && frame<80) {masked_blit( bitmap, buffer, 49,67, screen_x, screen_y, 17, 20);}
            else if( frame>=80 && frame<100) {masked_blit( bitmap, buffer, 49,88, screen_x, screen_y, 26, 20);}
		}
	}
}

void Player::delete_bitmap()
{
    destroy_bitmap(bitmap);
}

void Player::check_key()
{
	if( key[KEY_UP] && key[KEY_RIGHT])
    {
		move = true;
        direction = up_right;
		go_up();
        go_right();
    }
    else if( key[KEY_RIGHT] && key[KEY_DOWN])
    {
		move = true;
		direction = right_down;
        go_right();
        go_down();
    }
    else if( key[KEY_DOWN] && key[KEY_LEFT])
	{
		move = true;
		direction = down_left;
        go_down();
        go_left();
    }
    else if( key[KEY_LEFT] && key[KEY_UP])
    {
		move = true;
		direction = left_up;
        go_left();
        go_up();
    }
    else if (key[KEY_UP] && (collision == false || edge == up_edge || edge == left_edge || edge == right_edge))
	{
		move = true;
		direction = up;
		edge = down_edge;
        go_up();
    }
    else if( key[KEY_RIGHT] && (collision == false || edge == right_edge))
	{
		move = true;
		direction = right;
		edge = left_edge;
        go_right();
    }
    else if( key[KEY_DOWN] && (collision == false || edge == down_edge || edge == left_edge || edge == right_edge))
    {
		move = true;
		direction = down;
		edge = up_edge;
        go_down();
    }
    else if( key[KEY_LEFT] && (collision == false || edge == left_edge))
	{
		move = true;
		direction = left;
		edge = right_edge;
        go_left();
    }
    else if( key[KEY_SPACE] )
	{

    }
	else {move = false;}
}

void Player::go_up()
{
    map_y = map_y - add;
    if (map_y <= (World::screen_h / 2) - 1)
        screen_y = screen_y - add;
    else if (map_y >= (World::map_h - World::screen_h / 2) - 1)
        screen_y = screen_y - add;
    else
        scroll_y = scroll_y - add;
}

void Player::go_down()
{
    map_y = map_y + add;
    if (map_y <= (World::screen_h/2)) screen_y = screen_y + add;
    else if (map_y >= (World::map_h - World::screen_h / 2)) screen_y = screen_y + add;
    else scroll_y = scroll_y + add;
}

void Player::go_left()
{
    map_x = map_x - add;
    if (map_x <= (World::screen_w/2)-1) screen_x = screen_x - add;
    else if (map_x >= (World::map_w-World::screen_w/2)-1) screen_x = screen_x - add;
    else scroll_x = scroll_x - add;
}

void Player::go_right()
{
    map_x = map_x + add;
    if (map_x <= (World::screen_w/2)) screen_x = screen_x + add;
    else if (map_x >= (World::map_w - World::screen_w / 2)) screen_x = screen_x + add;
    else scroll_x = scroll_x + add;
}

void Player::calculate_coords_and_stuff()
{
    map_x1 = map_x + width;
	map_y1 = map_y + height;
	map_X = map_x / 32;
    map_Y = map_y / 32;
    map_X1 = map_x1 / 32;
    map_Y1 = map_y1 / 32;

//    ammo = (ammo_2x3 * 50);
//    grenades = grenade_2x4 + grenade_3x3 + grenade_3x4;
//    energy = 50 + (first_aid_3x1 * 25);
//    if (energy >= 100) energy = 100;
}
