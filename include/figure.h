#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

#include "util.h"

class Figure {
    public:
        void Move(double px, double py);
        virtual void Draw() = 0;
        bool movable, drawable;
        Center pos, vel, size;
        Color color;
        void SetDefaultVel(Center pvel);
        void ResetVel();
    private:
        Center defaultVel;
};

#endif