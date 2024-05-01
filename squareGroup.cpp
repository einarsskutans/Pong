#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

SquareGroup::SquareGroup() {
    std::cout << "\nDefault constructor called SQUAREGROUP " << this;
}
SquareGroup::SquareGroup(std::vector<Figure*> pfigures, double pfiguresgapx, double pfiguresgapy, double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called SQUAREGROUP " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable, drawable = pdrawable;
    figures = pfigures;
    figuresgapx = pfiguresgapx;
    figuresgapy = pfiguresgapy;
}
SquareGroup::~SquareGroup() {
    std::cout << "\nDestructor called SQUAREGROUP " << this;
}
void SquareGroup::Draw() {
    al_draw_rectangle(pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2, al_map_rgb(color.r, color.g, color.b), 2);
    int n = 0;
    for (Figure* figure : figures) {
        al_draw_filled_rectangle(pos.x - figure->size.x/2 - n*figuresgapx-figure->size.x, pos.y - figure->size.y/2 - n*figuresgapy, pos.x + figure->size.x/2-n*figuresgapx-figure->size.x, pos.y + figure->size.y/2 - n*figuresgapy, al_map_rgb(figure->color.r, figure->color.g, figure->color.b));
        n++;
    }
}