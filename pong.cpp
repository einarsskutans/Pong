#include <algorithm>
#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/pong.h"
#include "include/circle.h"
#include "include/square.h"
#include "include/physics.h"

Pong::Pong() {
    std::cout << "\nDefault constructor called " << this;

    Color white(255, 255, 255), blueBorder(71, 147, 175), black(0, 0, 0); // Declare some colors

    Circle *ball = new Circle(SCREEN_W/2, SCREEN_H/2, 5, 5, 25, 25, black, true);
    Square *playingArea = new Square(SCREEN_W/2, SCREEN_H/2, 0, 0, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder, false);
    Square *racketLeft = new Square(playingArea->pos.x - playingArea->size.x/2 - 10, playingArea->pos.y, 0, 25, 20, playingArea->size.y/4, white, false);
    Square *racketRight = new Square(playingArea->pos.x + playingArea->size.x/2 + 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, false);
    PFigures = {playingArea, ball, racketLeft, racketRight}; // Removed a bunch of Add() to reduce lines
    
}
Pong::~Pong() {
    std::cout << "\nDestructor called " << this;

    std::for_each(PFigures.cbegin(), PFigures.cend(), [](Figure* PFigure){delete PFigure;});
}

void Pong::Next() { // Game loop
    Physics::CollideInnerBounds(PFigures[1], PFigures[0]);

    // Left racket PFigures[2], has no collision checks it's purely deco
    if ( // Racket's pos.y is attached directly to ball's pos.y, horrendous algorithm
        PFigures[1]->pos.y < PFigures[0]->pos.y+PFigures[0]->size.y/2 - PFigures[2]->size.y/2 && 
        PFigures[1]->pos.y > PFigures[0]->pos.y-PFigures[0]->size.y/2 + PFigures[2]->size.y/2
        ) {
        PFigures[2]->pos.y = PFigures[1]->pos.y;
    }
    //

    for (Figure* PFigure : PFigures) { // Add velocity
        if (PFigure->movable) {
            PFigure->Move(PFigure->pos.x + PFigure->vel.x, PFigure->pos.y + PFigure->vel.y);
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
