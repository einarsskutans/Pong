#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

Ring::Ring() {
    std::cout << "\nDefault constructor called RING " << this;
}
Ring::Ring(double px, double py, double pvelx, double pvely, double psizex, double psizey, double pthickness, Color pcolor, Color pbgcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called RING " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, thickness = pthickness, color = pcolor, bgcolor = pbgcolor,  movable = pmovable, drawable = pdrawable;
}
Ring::~Ring() {
    std::cout << "\nDestructor called RING " << this;
}
void Ring::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(color.r, color.g, color.b));
    al_draw_filled_circle(pos.x, pos.y, size.x/2-thickness, al_map_rgb(bgcolor.r, bgcolor.g, bgcolor.b));
}