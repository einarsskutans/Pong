#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
    public:
        Circle();
        Circle(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor);
        ~Circle();
        void Draw();
};

#endif