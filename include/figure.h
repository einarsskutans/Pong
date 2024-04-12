#ifndef FIGURE_H
#define FIGURE_H

#include "util.h"

class Figure {
    public:
        void Move();
        virtual void Draw() = 0;
        Center pos, vel, size;
        Color color;
};

#endif