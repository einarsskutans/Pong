#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

#include "util.h"

class Figure {
    public:
        void Move(int px, int py);
        virtual void Draw() = 0;
        bool movable;
        Center pos, vel, size;
        Color color;
};

#endif