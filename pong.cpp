#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/pong.h"
#include "include/circle.h"
#include "include/square.h"

Pong::Pong() {
    std::cout << "\nDefault constructor called " << this;

    Color white(255, 255, 255);
    Color blueBorder(71, 147, 175);
    Circle *circle = new Circle(SCREEN_W/2, SCREEN_H/2, 20, 10, 10, 10, white);
    Square *square = new Square(SCREEN_W/2, SCREEN_H/2, 999, 999, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder);
    Add(square);
    Add(circle);
}
Pong::~Pong() {
    std::cout << "\nDestructor called " << this;

    for (Figure* PFigure : PFigures) {
        delete PFigure;
    }
}

void Pong::Next() {
    for (Figure* PFigure : PFigures) {
        if (PFigure->vel.x != 999 && PFigure->vel.y != 999) { // Don't apply physics to these objects
            PFigure->Move();
        }
    }
}
void Pong::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (Figure* PFigure : PFigures) {
        PFigure->Draw();
    }
}
void Pong::Add(Figure* PFigure) {
    PFigures.push_back(PFigure);
}
