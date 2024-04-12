#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/circle.h"

Circle::Circle() {
    std::cout << "\nDefault constructor called " << this;
}
Circle::Circle(int px, int py, int pvelx, int pvely, int psizex, int psizey) {
    std::cout << "\nConstructor called " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey;
}
Circle::~Circle() {
    std::cout << "\nDestructor called " << this;
}
void Circle::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(255, 255, 255));
}