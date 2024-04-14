#include <algorithm>
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

    Color white(255, 255, 255), blueBorder(71, 147, 175), black(0, 0, 0); // Declare some colors

    Circle *circle = new Circle(SCREEN_W/2, SCREEN_H/2, 5, 5, 25, 25, black, true);
    Square *square = new Square(SCREEN_W/2, SCREEN_H/2, 0, 0, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder, false);
    Add(square);
    Add(circle);
}
Pong::~Pong() {
    std::cout << "\nDestructor called " << this;

    std::for_each(PFigures.cbegin(), PFigures.cend(), [](Figure* PFigure){delete PFigure;});
}

void Pong::Next() {
    for (Figure* PFigure : PFigures) {
        if (PFigure->movable) { // Don't apply physics to these objects
            PFigure->Move(PFigures);
        }
    }
}
void Pong::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    std::for_each(PFigures.cbegin(), PFigures.cend(), [](Figure* PFigure){PFigure->Draw();});
}
void Pong::Add(Figure* PFigure) {
    PFigures.push_back(PFigure);
}
