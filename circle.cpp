#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/circle.h"

Circle::Circle() {
    std::cout << "\nDefault constructor called " << this;
}
Circle::Circle(Center pPos, Center pVel, Center pSize) {
    std::cout << "\nConstructor called " << this;
    pos = pPos, vel = pVel, size = pSize;
}
Circle::~Circle() {
    std::cout << "\nDestructor called " << this;
}
void Circle::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(255, 255, 255));
}