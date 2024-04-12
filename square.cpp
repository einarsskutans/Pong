#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/square.h"

Square::Square() {
    std::cout << "\nDefault constructor called " << this;
}
Square::Square(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor) {
    std::cout << "\nConstructor called " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor;
}
Square::~Square() {
    std::cout << "\nDestructor called " << this;
}
void Square::Draw() {
    al_draw_filled_rectangle(pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2, al_map_rgb(color.r, color.g, color.b));
}