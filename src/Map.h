#ifndef MAP_H
#define MAP_H
#include <allegro.h>

class Map
{
    public:
        static const int width = 40;
        static const int height = 30;

        Map();
        virtual ~Map();
        void display(BITMAP * & buffer, BITMAP * & tiles);

    protected:

    private:
};

#endif // MAP_H
