#include <algorithm>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/pong.h"
#include "include/circle.h"
#include "include/square.h"
#include "include/physics.h"
#include "include/image.h"

Pong& Pong::GetInstance() { // Singleton
    static Pong instance;
    return instance;
}

Pong::Pong() {
    std::cout << "\nDefault constructor called PONG " << this;

    Color white(255, 255, 255), blueBorder(71, 147, 175), black(0, 0, 0), gray(96, 96, 96); // Declare some colors
    Colors = {white, blueBorder, black, gray};
    Circle *ball = new Circle(SCREEN_W/2, SCREEN_H/2, 10, 5, 25, 25, black, true);
    Square *playingArea = new Square(SCREEN_W/2, SCREEN_H/2, 0, 0, SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8, blueBorder, false);
    Square *racketLeft = new Square(playingArea->pos.x - playingArea->size.x/2 - 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true);
    Square *racketRight = new Square(playingArea->pos.x + playingArea->size.x/2 + 10, playingArea->pos.y, 0, 0, 20, playingArea->size.y/4, white, true);

    ALLEGRO_BITMAP *bitmap = al_load_bitmap("heart.png");
    Image *img = new Image(200, 200, 0, 0, 20, 20, black, false, bitmap);
    Figures = {playingArea, ball, racketLeft, racketRight, img}; // Removed a bunch of Add() to reduce lines
}
Pong::~Pong() {
    std::cout << "\nDestructor called PONG " << this;

    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){delete figure;});
}

int startingTicks = 0; // Too lazy for deltaTime this works

void Pong::Next() { // Game loop
    Physics::CollideInnerBounds(Figures[ball], Figures[playingArea]);
    Physics::RacketFollowBall(Figures[racketLeft], Figures[ball], Figures[playingArea]); // Left racket has no collision checks, it's purely deco

    // Lose game condition
    if (
        Figures[ball]->pos.x + Figures[ball]->size.x/2 >= Figures[playingArea]->pos.x + Figures[playingArea]->size.x/2 &&
        !Physics::CollideCheck(Figures[ball], Figures[racketRight])
    ) {
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
