#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
    public:
        Square();
        Square(Center ppos, Center pvel, Center psize, Color pcolor, bool pmovabale, bool pdrawable);
        ~Square();
        void Draw();
};

#endif