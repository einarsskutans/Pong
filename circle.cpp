#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Circle::Circle() {
    std::cout << "\nDefault constructor called CIRCLE " << this;
}
Circle::Circle(Center ppos, Center pvel, Center psize, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called CIRCLE " << this;
    SetPos(ppos);
    SetVel(pvel);
    SetSize(psize);

    SetMovable(pmovable);
    SetDrawable(pdrawable);
}
Circle::~Circle() {
    std::cout << "\nDestructor called CIRCLE " << this;
}
void Circle::Draw() {
    al_draw_filled_circle(GetPos().x, GetPos().y, GetSize().x/2, al_map_rgb(color.r, color.g, color.b));
}