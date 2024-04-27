#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Circle::Circle() {
    std::cout << "\nDefault constructor called CIRCLE " << this;
}
Circle::Circle(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor, bool pmovable) {
    std::cout << "\nConstructor called CIRCLE " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable;
}
Circle::~Circle() {
    std::cout << "\nDestructor called CIRCLE " << this;
}
void Circle::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(color.r, color.g, color.b));
}