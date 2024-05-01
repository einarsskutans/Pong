#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
    public:
        Square();
        Square(double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovabale, bool pdrawable);
        ~Square();
        void Draw();
};

#endif