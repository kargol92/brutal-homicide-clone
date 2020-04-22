#include "World.h"

void World::load_bitmap()
{
    tiles = load_bmp ("graphics/tiles.bmp", default_palette);
}
void World::draw_bitmap(BITMAP* &buffer)
{
}
void World::delete_bitmap()
{
    destroy_bitmap(tiles);
}

void World::draw(BITMAP * & buffer)
{
//	for (int y = 0; y < map_H; y++)
//    {
//		for (int x = 0; x < map_W; x++)
//        {
//			if (map[y][x] == 0)   {blit (tiles, buffer, 0, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (map[y][x] == 1)   {blit (tiles, buffer, 0, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (map[y][x] == 2)   {blit (tiles, buffer, 32, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (map[y][x] == 3)   {blit (tiles, buffer, 64, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 100) {blit (tiles, buffer, 64, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 110) {blit (tiles, buffer, 128, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 120) {blit (tiles, buffer, 96, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (map[y][x] == 200) {blit (tiles, buffer, 32, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//        }
//    }
}
