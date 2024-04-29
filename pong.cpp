#include <algorithm>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <chrono> // For delta time purposes

#include "include/AllegroBase.hpp"

Pong& Pong::GetInstance() { // Singleton
    static Pong instance;
    return instance;
}

Pong::Pong() {
    std::cout << "\nDefault constructor called PONG " << this;

    Color white(255, 255, 255), blueBorder(71, 147, 175), black(0, 0, 0), gray(96, 96, 96), red(255, 0, 0); // Declare some colors
    Colors = {white, blueBorder, black, gray};
    Circle *ball = new Circle(SCREEN_W/2, SCREEN_H/2, 10, 5, 25, 25, black, true);
    Square *playingArea = new Square(SCREEN_W/2, SCREEN_H/2, 0, 0, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder, false);
    Square *racketLeft = new Square(playingArea->pos.x - playingArea->size.x/2 - 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true);
    Square *racketRight = new Square(playingArea->pos.x + playingArea->size.x/2 + 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true);
    Figures = {playingArea, ball, racketLeft, racketRight}; // Removed a bunch of Add() to reduce lines

    blackBorderSize = Center((SCREEN_W-playingArea->size.x)/2, (SCREEN_H-playingArea->size.y)/2);

    for (int i = 0; i < maxLives; i++) { // Push-back lives shapes to Figures{}
        Square *life = new Square((blackBorderSize.x+10)+i*10*2, SCREEN_H-blackBorderSize.y/2, 0, 0, 10, 10, white, false);
        Add(life);
    }
}
Pong::~Pong() {
    std::cout << "\nDestructor called PONG " << this;

    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){delete figure;});
}

int startingTicks = 0; // Too lazy for deltaTime this works
bool ballCollideSides; // Ensures proper lives variable subtraction

void Pong::Next() { // Game loop
    Physics::CollideInnerBounds(Figures[ball], Figures[playingArea]);
    Physics::RacketFollowBall(Figures[racketLeft], Figures[ball], Figures[playingArea]); // Left racket has no collision checks, it's purely deco

    if (
        !Physics::CollideCheck(Figures[ball], Figures[racketRight]) &&
        Figures[ball]->pos.x + Figures[ball]->size.x/2 >= Figures[playingArea]->pos.x + Figures[playingArea]->size.x/2 &&
        !ballCollideSides
    ) {
        ballCollideSides = true;
        lives--;
        Figures.pop_back(); // Pops the life shapes, risky without a conditional ._.
    } else if (
        !Physics::CollideCheck(Figures[ball], Figures[racketRight]) &&
        Figures[ball]->pos.x + Figures[ball]->size.x/2 < Figures[playingArea]->pos.x + Figures[playingArea]->size.x/2
    ) {
        ballCollideSides = false;
    }

    // Lose game condition
    if (lives < 1) {
        Figures[playingArea]->color = Colors[3];
        std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){figure->movable = false;});
    }

    // Move all figures
    if (startingTicks > 60 * 2) {
        for (Figure* figure : Figures) { // Add velocity
            if (figure->movable) {
                figure->Move(figure->pos.x + figure->vel.x, figure->pos.y + figure->vel.y);
            }
        }
    }
    startingTicks++;
}
void Pong::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){figure->Draw();});
}
void Pong::Add(Figure* figure) {
    Figures.push_back(figure);
}
