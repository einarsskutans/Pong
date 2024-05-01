#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Circle::Circle() {
    std::cout << "\nDefault constructor called CIRCLE " << this;
}
Circle::Circle(double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called CIRCLE " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable, drawable = pdrawable;
}
Circle::~Circle() {
    std::cout << "\nDestructor called CIRCLE " << this;
}
void Circle::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(color.r, color.g, color.b));
}