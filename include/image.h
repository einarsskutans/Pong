#ifndef IMAGE_H
#define IMAGE_H

#include "AllegroBase.hpp"
#include "figure.h"

class Image : public Figure {
    public:
        Image();
        Image(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor, bool pmovabale);
        ~Image();
        void Draw();
};

#endif