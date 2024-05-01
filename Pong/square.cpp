#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Square::Square() {
    std::cout << "\nDefault constructor called SQUARE " << this;
}
Square::Square(double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called SQUARE " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable, drawable = pdrawable;
}
Square::~Square() {
    std::cout << "\nDestructor called SQUARE " << this;
}
void Square::Draw() {
    al_draw_filled_rectangle(pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2, al_map_rgb(color.r, color.g, color.b));
}