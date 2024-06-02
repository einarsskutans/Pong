#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

#include "util.h"

class Figure {
    public:
        void Move(double px, double py);
        virtual void Draw() = 0;

        void SetDefaultVel(Center pvel);
        void ResetVel();
        Center GetSize();
        Center GetPos();
        Center GetVel();
        void SetPos(Center ppos);
        void SetVel(Center pvel);
        void SetSize(Center psize);


        bool IsMovable();
        bool IsDrawable();
        void SetMovable(bool pmovable);
        void SetDrawable(bool pdrawable);

        Color color;
    private:
        Center defaultVel;
        Center pos, vel, size;
        bool movable, drawable;
};

#endif