#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Square::Square() {
    std::cout << "\nDefault constructor called SQUARE " << this;
}
Square::Square(Center ppos, Center pvel, Center psize, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called SQUARE " << this;
    SetPos(ppos);
    SetVel(pvel);
    SetSize(psize);

    SetMovable(pmovable);
    SetDrawable(pdrawable);
}
Square::~Square() {
    std::cout << "\nDestructor called SQUARE " << this;
}
void Square::Draw() { // Change operators
    al_draw_filled_rectangle(GetPos().x - GetSize().x/2, GetPos().y - GetSize().y/2, GetPos().x + GetSize().x/2, GetPos().y + GetSize().y/2, al_map_rgb(color.r, color.g, color.b));
}