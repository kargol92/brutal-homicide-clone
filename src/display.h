// display.h

////////////////////////////////////////////////////////////////////////////////
// displaying map //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void display_map(BITMAP * & buffer, BITMAP * & tiles)
{
	for (int y = 0; y < map_H; y++)
    {
		for (int x = 0; x < map_W; x++)
        {
			if (map[y][x] == 0)   {blit (tiles, buffer, 0, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
			if (map[y][x] == 1)   {blit (tiles, buffer, 0, 32, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
			if (map[y][x] == 2)   {blit (tiles, buffer, 32, 32, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
			if (map[y][x] == 3)   {blit (tiles, buffer, 64, 32, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 100) {blit (tiles, buffer, 64, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 110) {blit (tiles, buffer, 128, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 120) {blit (tiles, buffer, 96, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
            if (map[y][x] == 200) {blit (tiles, buffer, 32, 0, (x*World::tile_w)-(scroll_x), (y*World::tile_h)-(scroll_y), World::tile_w, World::tile_h);}
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// displaying coords and stuff /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void display_coords_and_stuff(BITMAP * & buffer)
{
	textprintf_ex(buffer, font, 440,  5, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player.map_X, player.map_Y );
    textprintf_ex(buffer, font, 440, 15, makecol( 255, 255, 128 ), -1, "map:    x %d y %d", player.map_x, player.map_y );
    textprintf_ex(buffer, font, 440, 25, makecol( 255, 255, 128 ), -1, "screen: x %d y %d", player.screen_x, player.screen_y );
    textprintf_ex(buffer, font, 440, 35, makecol( 255, 255, 128 ), -1, "scroll: x %d y %d", scroll_x, scroll_y );
    textprintf_ex(buffer, font, 440, 45, makecol( 255, 255, 128 ), -1, "frame: %d", frame );
    textprintf_ex(buffer, font, 440, 205, makecol( 255, 255, 128 ), -1, "MAP:    X %d Y %d", player.map_X1, player.map_Y1 );
    textprintf_ex(buffer, font, 440, 215, makecol( 255, 255, 128 ), -1, "map:    x %d y %d", player.map_x1, player.map_y1 );
    textprintf_ex(buffer, font, 440, 225, makecol( 255, 255, 128 ), -1, "collision: %d", player.collision );

    if 		(player.direction == 1) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP)", player.direction );
    else if (player.direction == 2) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (UP-RIGHT)", player.direction );
    else if (player.direction == 3) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT)", player.direction );
    else if (player.direction == 4) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (RIGHT-DOWN)", player.direction );
    else if (player.direction == 5) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN)", player.direction );
    else if (player.direction == 6) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (DOWN-LEFT)", player.direction );
    else if (player.direction == 7) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT)", player.direction );
    else if (player.direction == 8) textprintf_ex(buffer, font, 440, 95, makecol( 255, 255, 128 ), -1, "direction: %d (LEFT-UP)", player.direction );
	if 		(player.edge == 1) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (UP)", player.edge );
    else if (player.edge == 3) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (RIGHT)", player.edge );
    else if (player.edge == 5) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (DOWN)", player.edge );
    else if (player.edge == 7) textprintf_ex(buffer, font, 440, 105, makecol( 255, 255, 128 ), -1, "edge of wall %d (LEFT)", player.edge );

    textprintf_ex(buffer, font, 440, 115, makecol( 255, 255, 128 ), -1, "map[1][5]: %d", map[1][5] );
    textprintf_ex(buffer, font, 5, 440, makecol( 255, 255, 128 ), -1, "ammo: %d", player.ammo );
    textprintf_ex(buffer, font, 5, 450, makecol( 255, 255, 128 ), -1, "grenades: %d", player.grenades );
    textprintf_ex(buffer, font, 5, 460, makecol( 255, 255, 128 ), -1, "energy: %d", player.energy );
}
