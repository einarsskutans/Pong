#ifndef FIGURE_H
#define FIGURE_H

#include "util.h"

class Figure {
    public:
        void Move();
        virtual void Draw();
        Center pos, vel, size;
    private:
        void Reset(Center pPos);
};

#endif