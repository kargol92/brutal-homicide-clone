#include "Map.h"

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::display(BITMAP * & buffer, BITMAP * & tiles)
{
//	for (int y = 0; y < height; y++)
//    {
//		for (int x = 0; x < width; x++)
//        {
//			if (array[y][x] == 0)   {blit (tiles, buffer, 0, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (array[y][x] == 1)   {blit (tiles, buffer, 0, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (array[y][x] == 2)   {blit (tiles, buffer, 32, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//			if (array[y][x] == 3)   {blit (tiles, buffer, 64, 32, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 100) {blit (tiles, buffer, 64, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 110) {blit (tiles, buffer, 128, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 120) {blit (tiles, buffer, 96, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 121) {blit (tiles, buffer, 160, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 122) {blit (tiles, buffer, 192, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 123) {blit (tiles, buffer, 224, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//            if (array[y][x] == 200) {blit (tiles, buffer, 32, 0, (x*tile_w)-(scroll_x), (y*tile_h)-(scroll_y), tile_w, tile_h);}
//        }
//    }
}
