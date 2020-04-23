#include "World.h"

void World::load_map()
{
    fstream file;

    string line;

    file.open("map.txt", ios::in);

    if (file.good())
    {
        while (!file.eof())
        {
            getline(file, line);
            if (rows_count == 0)
                cols_count = line.length();
            rows_count++;
        }
        file.close();
    }

    file.open("map.txt", ios::in);

    map2 = new char*[rows_count];
    for (int i = 0; i < rows_count; ++i)
        map2[i] = new char[cols_count];

    string *lines = new string[rows_count];
    rows_count = 0;

    if (file.good())
    {
        while (!file.eof())
        {
            getline(file, lines[rows_count]);
            //strcpy(tab2, temp.c_str());
            rows_count++;
        }
        file.close();
    }

    for (int i=0; i<rows_count; i++)
        strcpy(map2[i], lines[i].c_str());
}

void World::delete_map()
{
    for (int i = 0; i < rows_count; ++i)
        delete [] map2[i];

    delete [] map2;
}

void World::load_bitmap()
{
    tiles = load_bmp ("graphics/tiles.bmp", default_palette);
}

void World::delete_bitmap()
{
    destroy_bitmap(tiles);
}
void World::draw(BITMAP* &buffer, Player player)
{
	for (int y = 0; y < map_H; y++)
    {
		for (int x = 0; x < map_W; x++)
        {
			if (map[y][x] == ' ') {blit (tiles, buffer, 0, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map[y][x] == '%') {blit (tiles, buffer, 0, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map[y][x] == 'o') {blit (tiles, buffer, 32, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map[y][x] == '+') {blit (tiles, buffer, 64, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == '#') {blit (tiles, buffer, 64, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == '-') {blit (tiles, buffer, 128, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == '|') {blit (tiles, buffer, 96, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map[y][x] == '&') {blit (tiles, buffer, 32, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
        }
    }
}

void World::draw2(BITMAP* &buffer, Player player)
{
	for (int y = 0; y < rows_count; y++)
    {
		for (int x = 0; x < cols_count; x++)
        {
			if (map2[y][x] == '_') {blit (tiles, buffer, 0, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map2[y][x] == '%') {blit (tiles, buffer, 0, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map2[y][x] == 'o') {blit (tiles, buffer, 32, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
			if (map2[y][x] == '+') {blit (tiles, buffer, 64, 32, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == '#') {blit (tiles, buffer, 64, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == '-') {blit (tiles, buffer, 128, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == '|') {blit (tiles, buffer, 96, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
            if (map2[y][x] == '&') {blit (tiles, buffer, 32, 0, (x*tile_w)-(player.scroll_x), (y*tile_h)-(player.scroll_y), tile_w, tile_h);}
        }
    }
}

void World::display_info(BITMAP* &buffer, Player player1, int frame)
{
	textprintf_ex(buffer, font, 440,  5, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player1.map_X, player1.map_Y );
    textprintf_ex(buffer, font, 440, 15, makecol( 255, 255, 128 ), -1, "map:    x %.1f y %.1f", player1.map_x, player1.map_y );
    textprintf_ex(buffer, font, 440, 25, makecol( 255, 255, 128 ), -1, "screen: x %.1f y %.1f", player1.screen_x, player1.screen_y );
    textprintf_ex(buffer, font, 440, 35, makecol( 255, 255, 128 ), -1, "scroll: x %.1f y %.1f", player1.scroll_x, player1.scroll_y );
    textprintf_ex(buffer, font, 440, 45, makecol( 255, 255, 128 ), -1, "frame: %d", frame );
    textprintf_ex(buffer, font, 440, 205, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player1.map_X1, player1.map_Y1 );
    textprintf_ex(buffer, font, 440, 215, makecol( 255, 255, 128 ), -1, "map:    x %.1f y %.1f", player1.map_x1, player1.map_y1 );
    textprintf_ex(buffer, font, 440, 225, makecol( 255, 255, 128 ), -1, "collision: %d", player1.collision );

//    textprintf_ex(buffer, font, 440, 235, makecol( 255, 255, 128 ), -1, "map2:    %dx%d", rows_count, cols_count );
//
//    for (int y=0; y<rows_count; y++)
//    {
//        for (int x=0; x<cols_count; x++)
//        {
//            textprintf_ex(buffer, font, 150 + x*7, 5 + y*10, makecol( 255, 255, 128 ), -1, "%c", map2[y][x] );
//        }
//    }

    if 		(player1.direction == 1) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP)", player1.direction );
    else if (player1.direction == 2) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP-RIGHT)", player1.direction );
    else if (player1.direction == 3) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT)", player1.direction );
    else if (player1.direction == 4) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT-DOWN)", player1.direction );
    else if (player1.direction == 5) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN)", player1.direction );
    else if (player1.direction == 6) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN-LEFT)", player1.direction );
    else if (player1.direction == 7) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT)", player1.direction );
    else if (player1.direction == 8) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT-UP)", player1.direction );

	if 		(player1.edge == 1) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (UP)", player1.edge );
    else if (player1.edge == 3) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (RIGHT)", player1.edge );
    else if (player1.edge == 5) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (DOWN)", player1.edge );
    else if (player1.edge == 7) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (LEFT)", player1.edge );

    textprintf_ex(buffer, font, 440, 115, makecol( 255, 255, 128 ), -1, "map[1][5]: %d", map[1][5] );
    textprintf_ex(buffer, font, 5, 440, makecol( 255, 255, 128 ), -1, "ammo: %d", player1.ammo );
    textprintf_ex(buffer, font, 5, 450, makecol( 255, 255, 128 ), -1, "grenades: %d", player1.grenades );
    textprintf_ex(buffer, font, 5, 460, makecol( 255, 255, 128 ), -1, "energy: %d", player1.energy );
}
