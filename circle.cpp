#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/circle.h"

Circle::Circle() {}
Circle::Circle(Center pPos, Center pVel, Center pSize) {
    pos = pPos, vel = pVel, size = pSize;
}
void Circle::Draw() {
    al_draw_filled_circle(pos.x, pos.y, size.x/2, al_map_rgb(255, 255, 255));
}