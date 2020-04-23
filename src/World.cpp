#include "World.h"

void World::load_bitmap()
{
    tiles = load_bmp ("graphics/tiles.bmp", default_palette);
}

void World::delete_bitmap()
{
    destroy_bitmap(tiles);
}

void World::draw(BITMAP* &buffer, Player* &player)
{
	for (int y = 0; y < map_H; y++)
    {
		for (int x = 0; x < map_W; x++)
        {
			if (map[y][x] ==  0 ) {blit (tiles, buffer, 0, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
			if (map[y][x] == '%') {blit (tiles, buffer, 0, 32, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
			if (map[y][x] == 'o') {blit (tiles, buffer, 32, 32, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
			if (map[y][x] == '+') {blit (tiles, buffer, 64, 32, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == '#') {blit (tiles, buffer, 64, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == '-') {blit (tiles, buffer, 128, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == '|') {blit (tiles, buffer, 96, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
            if (map[y][x] == '&') {blit (tiles, buffer, 32, 0, (x*tile_w)-(player->scroll_x), (y*tile_h)-(player->scroll_y), tile_w, tile_h);}
        }
    }
}

void World::display_info(BITMAP* &buffer, Player* player1, int frame)
{
	textprintf_ex(buffer, font, 440,  5, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player1->map_X, player1->map_Y );
    textprintf_ex(buffer, font, 440, 15, makecol( 255, 255, 128 ), -1, "map:    x %.1f y %.1f", player1->map_x, player1->map_y );
    textprintf_ex(buffer, font, 440, 25, makecol( 255, 255, 128 ), -1, "screen: x %.1f y %.1f", player1->screen_x, player1->screen_y );
    textprintf_ex(buffer, font, 440, 35, makecol( 255, 255, 128 ), -1, "scroll: x %.1f y %.1f", player1->scroll_x, player1->scroll_y );
    textprintf_ex(buffer, font, 440, 45, makecol( 255, 255, 128 ), -1, "frame: %d", frame );
    textprintf_ex(buffer, font, 440, 205, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player1->map_X1, player1->map_Y1 );
    textprintf_ex(buffer, font, 440, 215, makecol( 255, 255, 128 ), -1, "map:    x %d y %d", player1->map_x1, player1->map_y1 );
    textprintf_ex(buffer, font, 440, 225, makecol( 255, 255, 128 ), -1, "collision: %d", player1->collision );

    if 		(player1->direction == 1) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP)", player1->direction );
    else if (player1->direction == 2) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP-RIGHT)", player1->direction );
    else if (player1->direction == 3) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT)", player1->direction );
    else if (player1->direction == 4) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT-DOWN)", player1->direction );
    else if (player1->direction == 5) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN)", player1->direction );
    else if (player1->direction == 6) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN-LEFT)", player1->direction );
    else if (player1->direction == 7) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT)", player1->direction );
    else if (player1->direction == 8) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT-UP)", player1->direction );
	if 		(player1->edge == 1) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (UP)", player1->edge );
    else if (player1->edge == 3) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (RIGHT)", player1->edge );
    else if (player1->edge == 5) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (DOWN)", player1->edge );
    else if (player1->edge == 7) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (LEFT)", player1->edge );

    textprintf_ex(buffer, font, 440, 115, makecol( 255, 255, 128 ), -1, "map[1][5]: %d", map[1][5] );
    textprintf_ex(buffer, font, 5, 440, makecol( 255, 255, 128 ), -1, "ammo: %d", player1->ammo );
    textprintf_ex(buffer, font, 5, 450, makecol( 255, 255, 128 ), -1, "grenades: %d", player1->grenades );
    textprintf_ex(buffer, font, 5, 460, makecol( 255, 255, 128 ), -1, "energy: %d", player1->energy );
}
