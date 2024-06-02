#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
    public:
        Circle();
        Circle(Center ppos, Center pvel, Center psize, Color pcolor, bool pmovable, bool pdrawable);
        ~Circle();
        void Draw();
};

#endif