#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

SquareGroup::SquareGroup() {
    std::cout << "\nDefault constructor called SQUAREGROUP " << this;
}
SquareGroup::SquareGroup(Center pfiguresgap, Center ppos, Center pvel, Center psize, Color pcolor, bool pmovable, bool pdrawable) {
    std::cout << "\nConstructor called SQUAREGROUP " << this;
    SetPos(ppos);
    SetVel(pvel);
    SetSize(psize);

    SetMovable(pmovable);
    SetDrawable(pdrawable);
    
    SetFiguresgap(pfiguresgap);
}
SquareGroup::~SquareGroup() {
    std::cout << "\nDestructor called SQUAREGROUP " << this;
}
void SquareGroup::Draw() {
    al_draw_rectangle(GetPos().x - GetSize().x/2, GetPos().y - GetSize().y/2, GetPos().x + GetSize().x/2, GetPos().y + GetSize().y/2, al_map_rgb(color.r, color.g, color.b), 1);
    int n = 0;
    for (Figure* figure : figures) {
        al_draw_filled_rectangle(GetPos().x - figure->GetSize().x/2 + n*GetFiguresgap().x, GetPos().y - figure->GetSize().y/2 + n*GetFiguresgap().y, GetPos().x + figure->GetSize().x/2 + n*GetFiguresgap().x, GetPos().y + figure->GetSize().y/2 + n*GetFiguresgap().y, al_map_rgb(figure->color.r, figure->color.g, figure->color.b));
        n++;
    }
}
Center SquareGroup::GetFiguresgap() {
    return figuresgap;
}

void SquareGroup::SetFiguresgap(Center pfiguresgap) {
    figuresgap = pfiguresgap;
}
