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

    Color white(255, 255, 255), blueBorder(71, 147, 175), black(0, 0, 0), gray(96, 96, 96), red(200, 0, 0); // Declare some colors
    Colors = {white, blueBorder, black, gray, red};
    Circle *ball = new Circle(SCREEN_W/2, SCREEN_H/2, 10, 5, 25, 25, black, true, true);
    Ring *ring = new Ring(0, 0, 0, 0, 50, 50, 2, gray, blueBorder, true, false);
    ball->SetDefaultVel(Center(10, 5));
    Square *playingArea = new Square(SCREEN_W/2, SCREEN_H/2, 0, 0, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder, false, true);
    Square *racketLeft = new Square(playingArea->pos.x - playingArea->size.x/2 - 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true, true);
    Square *racketRight = new Square(playingArea->pos.x + playingArea->size.x/2 + 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true, true);
    Figures = {playingArea, ring, ball, racketLeft, racketRight}; // Removed a bunch of Add() to reduce lines

    blackBorderSize = Center((SCREEN_W-playingArea->size.x)/2, (SCREEN_H-playingArea->size.y)/2);

    for (int i = 0; i < maxLives; i++) { // Push-back lives shapes to Figures{}
        Square *life = new Square((blackBorderSize.x+10)+i*10*2, SCREEN_H-blackBorderSize.y/2, 0, 0, 10, 10, white, false, true);
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

    if (Physics::CollideCheck(Figures[ball], Figures[racketRight]) && !ballCollideSides)  {
        // Scoring condtitionals -> ball behavior
        Figures[ball]->vel.x *= 1.05;
        if (Figures[ball]->vel.x > 20) {
            Figures[ball]->ResetVel();
        }
        switch (score)
        {
        case 12:
            Figures[ball]->drawable = true; // Turn the ring visible
            break;
        case 24:
            Figures[ring]->color.b -= 55; Figures[ring]->color.r -= 55;
        case 30:
            Figures[ring]->color = Colors[4];
        }

        score++;
        ballCollideSides = true;
    }
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

    Physics::Anchor(Figures[ring], Figures[ball]); // Ring always follows the ball

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
    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){if (figure->drawable){figure->Draw();}});
}
void Pong::Add(Figure* figure) {
    Figures.push_back(figure);
}
