#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Square::Square() {
    std::cout << "\nDefault constructor called SQUARE " << this;
}
Square::Square(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor, bool pmovable) {
    std::cout << "\nConstructor called SQUARE " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable;
}
Square::~Square() {
    std::cout << "\nDestructor called SQUARE " << this;
}
void Square::Draw() {
    al_draw_filled_rectangle(pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2, al_map_rgb(color.r, color.g, color.b));
}