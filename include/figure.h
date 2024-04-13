#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

#include "util.h"

class Figure {
    public:
        void Move(std::vector <Figure*> PFigures);
        virtual void Draw() = 0;
        Center pos, vel, size;
        Color color;
};

#endif