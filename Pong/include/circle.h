#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
    public:
        Circle();
        Circle(double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovable, bool pdrawable);
        ~Circle();
        void Draw();
};

#endif