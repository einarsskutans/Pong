#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

CircleGroup::CircleGroup() {
    std::cout << "\nDefault constructor called CIRCLEGROUP " << this;
}
CircleGroup::CircleGroup(std::vector<Figure*> pfigures, double pfiguresgapx, double pfiguresgapy, double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called CIRCLEGROUP " << this;
    pos.x = px, pos.y = py, vel.x = pvelx, vel.y = pvely, size.x = psizex, size.y = psizey, color = pcolor, movable = pmovable, drawable = pdrawable;
    figures = pfigures;
    figuresgapx = pfiguresgapx;
    figuresgapy = pfiguresgapy;
}
CircleGroup::~CircleGroup() {
    std::cout << "\nDestructor called CIRCLEGROUP " << this;
}
void CircleGroup::Draw() {
    al_draw_rectangle(pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2, al_map_rgb(color.r, color.g, color.b), 1);
    int n = 0;
    for (Figure* figure : figures) {
        al_draw_filled_rectangle(pos.x - figure->size.x/2 + n*figuresgapx, pos.y - figure->size.y/2 + n*figuresgapy, pos.x + figure->size.x/2 + n*figuresgapx, pos.y + figure->size.y/2 + n*figuresgapy, al_map_rgb(figure->color.r, figure->color.g, figure->color.b));
        n++;
    }
}