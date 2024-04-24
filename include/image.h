#ifndef IMAGE_H
#define IMAGE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "figure.h"

class Image : public Figure {
    public:
        Image();
        Image(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor, bool pmovabale, ALLEGRO_BITMAP *pplayer);
        ~Image();
        void Draw();

        ALLEGRO_BITMAP *player;
};

#endif