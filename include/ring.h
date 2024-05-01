#ifndef RING_H
#define RING_H

#include "figure.h"

class Ring : public Figure {
    public:
        Ring();
        Ring(double px, double py, double pvelx, double pvely, double psizex, double psizey, double pthickness, Color pcolor, Color pbgcolor, bool pmovable, bool pdrawable);
        ~Ring();
        void Draw();
        double thickness;
        Color bgcolor;
};

#endif