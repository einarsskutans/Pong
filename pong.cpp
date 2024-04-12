#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/pong.h"
#include "include/circle.h"

Pong::Pong() {
    std::cout << "\nDefault constructor called " << this;
    
}
Pong::~Pong() {
    std::cout << "\nDestructor called " << this;
}

void Pong::Next() {
    for (Figure* PFigure : PFigures) {
        if (PFigure->vel.x != 999 && PFigure->vel.y != 999) { // Don't apply physics to these objects
            PFigure->Move();
        }
    }
}
void Pong::Draw() {
    for (Figure* PFigure : PFigures) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        PFigure->Draw();
    }
}
void Pong::Add(Figure* PFigure) {
    PFigures.push_back(PFigure);
}
