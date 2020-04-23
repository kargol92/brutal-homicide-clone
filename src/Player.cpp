#include "Player.h"
#include "World.h"

extern World world;

Player::Player()
{
    direction = Direction::right;
    //edge = Edge::up_edge;
    map_x = 40;
    map_y = 40;
    map_X = map_x / World::tile_w;
    map_Y = map_y / World::tile_h;
    map_x1 = map_x + width;
    map_y1 = map_y + height;
    map_X1 = map_x1 / World::tile_w;
    map_Y1 = map_y1 / World::tile_h;
    screen_x = map_x;
    screen_y = map_y;

    move = false;
    run_speed = 0.7;
    collision = false;

    ammo = 0;
    grenades = 0;
    energy = 0;
    lives = 0;
    money = 0;
    weapon = 0;
}

Player::Player(int x, int y)
{

}

void Player::load_bitmap()
{
    bitmap = load_bmp ("graphics/player.bmp", default_palette);
}

void Player::draw(BITMAP* &buffer, int frame)
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
        direction = Direction::up_right;
		go_up();
        go_right();
    }
    else if( key[KEY_RIGHT] && key[KEY_DOWN])
    {
		move = true;
		direction = Direction::right_down;
        go_right();
        go_down();
    }
    else if( key[KEY_DOWN] && key[KEY_LEFT])
	{
		move = true;
		direction = Direction::down_left;
        go_down();
        go_left();
    }
    else if( key[KEY_LEFT] && key[KEY_UP])
    {
		move = true;
		direction = Direction::left_up;
        go_left();
        go_up();
    }
    else if (key[KEY_UP] && (collision == false || edge == up_edge || edge == left_edge || edge == right_edge))
	{
		move = true;
		direction = Direction::up;
		edge = Edge::down_edge;
        go_up();
    }
    else if( key[KEY_RIGHT] && (collision == false || edge == right_edge))
	{
		move = true;
		direction = Direction::right;
		edge = Edge::left_edge;
        go_right();
    }
    else if( key[KEY_DOWN] && (collision == false || edge == down_edge || edge == left_edge || edge == right_edge))
    {
		move = true;
		direction = Direction::down;
		edge = Edge::up_edge;
        go_down();
    }
    else if( key[KEY_LEFT] && (collision == false || edge == left_edge))
	{
		move = true;
		direction = Direction::left;
		edge = Edge::right_edge;
        go_left();
    }
    else if( key[KEY_SPACE] )
	{

    }
	else {move = false;}
}

void Player::go_up()
{
    map_y -= run_speed;
    if (map_y <= (World::screen_h / 2) - 1)
        screen_y -= run_speed;
    else if (map_y >= (World::map_h - World::screen_h / 2) - 1)
        screen_y -= run_speed;
    else
        scroll_y -= run_speed;
}

void Player::go_down()
{
    map_y += run_speed;
    if (map_y <= (World::screen_h / 2))
        screen_y += run_speed;
    else if (map_y >= (World::map_h - World::screen_h / 2))
        screen_y += run_speed;
    else
        scroll_y += run_speed;
}

void Player::go_left()
{
    map_x -= run_speed;
    if (map_x <= (World::screen_w/2) - 1)
        screen_x -= run_speed;
    else if (map_x >= (World::map_w-World::screen_w / 2) - 1)
        screen_x -= run_speed;
    else
        scroll_x -= run_speed;
}

void Player::go_right()
{
    map_x += run_speed;
    if (map_x <= (World::screen_w / 2))
        screen_x += run_speed;
    else if (map_x >= (World::map_w - World::screen_w / 2))
        screen_x += run_speed;
    else
        scroll_x += run_speed;
}

void Player::update()
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
