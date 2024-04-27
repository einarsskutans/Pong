#include <iostream>
#include "include/AllegroBase.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/image.h"

Image::Image() {
    std::cout << "\nDefault constructor called Image " << this;
}
Image::Image(int px, int py, int pvelx, int pvely, int psizex, int psizey, Color pcolor, bool pmovable) {
    std::cout << "\nConstructor called Image " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable;
    
}
Image::~Image() {
    std::cout << "\nDestructor called Image " << this;
}
void Image::Draw() {
    al_draw_bitmap(bitmap, pos.x, pos.y, 0);
}