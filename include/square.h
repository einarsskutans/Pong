#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
    public:
        Square();
        Square(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor);
        ~Square();
        void Draw();
};

#endif