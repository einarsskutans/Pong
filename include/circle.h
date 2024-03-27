#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
    public:
        Circle();
        Circle(Center pPos, Center pVel, Center pSize);
        ~Circle();
        void Draw();
};

#endif