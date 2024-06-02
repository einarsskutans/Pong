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

    Circle *ball = new Circle({SCREEN_W/2, SCREEN_H/2}, {10, 5}, {25, 25}, black, true, true);
    ball->SetDefaultVel(Center(10, 5));
    Square *playingArea = new Square({SCREEN_W/2, SCREEN_H/2}, {0, 0}, {SCREEN_W - SCREEN_W/8, SCREEN_H - SCREEN_H/8}, blueBorder, false, true);
    Square *racketLeft = new Square({playingArea->GetPos().x - playingArea->GetSize().x/2 - 10, playingArea->GetPos().y}, {0, 0}, {20, playingArea->GetSize().y/4}, white, true, true);
    Square *racketRight = new Square({playingArea->GetPos().x + playingArea->GetSize().x/2 + 10, playingArea->GetPos().y}, {0, 0}, {20, playingArea->GetSize().y/4}, white, true, true);
    
    blackBorderSize = Center((SCREEN_W-playingArea->GetSize().x)/2, (SCREEN_H-playingArea->GetSize().y)/2);
    //std::vector<Figure*> livesFigures;
    SquareGroup *livesSquares = new SquareGroup({30, 0}, {blackBorderSize.x+10, SCREEN_H-blackBorderSize.y/2}, {0, 0}, {24, 24}, black, false, true);
    Figures = {playingArea, ball, racketLeft, racketRight, livesSquares};
}
Pong::~Pong() {
    std::cout << "\nDestructor called PONG " << this;

    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){delete figure;});
}

bool ballCollideSides; // Ensures proper lives variable subtraction

void Pong::Next() { // Game loop
    //std::cout << (Figures[ball]->vel + Figures[racketRight]->pos).x << "\t" << (Figures[ball]->vel + Figures[racketRight]->pos).y << " \n";
    Physics::CollideInnerBounds(Figures[ball], Figures[playingArea]);
    Physics::RacketFollowBall(Figures[racketLeft], Figures[ball], Figures[playingArea]); // Left racket has no collision checks, it's purely deco

    if (Physics::CollideCheck(Figures[ball], Figures[racketRight]) && !ballCollideSides)  {
        // Scoring condtitionals -> ball behavior
        if (Figures[ball]->GetVel().x < 20) {
            Figures[ball]->SetSize({Figures[ball]->GetSize().y, Figures[ball]->GetSize().x*1.025});
            Figures[ball]->SetSize({Figures[ball]->GetSize().y*1.02, Figures[ball]->GetSize().x});
        }

        score++;
        ballCollideSides = true;
    }
    if (
        !Physics::CollideCheck(Figures[ball], Figures[racketRight]) &&
        Figures[ball]->GetPos().x + Figures[ball]->GetSize().x/2 >= Figures[playingArea]->GetPos().x + Figures[playingArea]->GetSize().x/2 &&
        !ballCollideSides
    ) {
        ballCollideSides = true;
        lives--;
        dynamic_cast<SquareGroup*>(Figures[lifeSquares])->figures.pop_back();
    } else if (
        !Physics::CollideCheck(Figures[ball], Figures[racketRight]) &&
        Figures[ball]->GetPos().x + Figures[ball]->GetSize().x/2 < Figures[playingArea]->GetPos().x + Figures[playingArea]->GetSize().x/2
    ) {
        ballCollideSides = false;
    }

    // Lose game condition
    if (lives < 1) {
        Figures[playingArea]->color = Colors[3];
        std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){figure->SetMovable(false);});
        gameRuns = false;
    }

    // Move all figures
    if (gameRuns) {
        for (Figure* figure : Figures) { // Add velocity
            if (figure->IsMovable()) {
                figure->Move(figure->GetVel().x + figure->GetPos().x, figure->GetVel().y + figure->GetPos().y);
            }
        }
    }
}
void Pong::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    std::for_each(Figures.cbegin(), Figures.cend(), [](Figure* figure){if (figure->IsDrawable()){figure->Draw();}});
}
void Pong::Add(Figure* figure) {
    Figures.push_back(figure);
}

//

void Pong::SetMaxLives(int n) {
    maxLives = n;
    lives = maxLives;
}
int Pong::GetMaxLives() {
    return maxLives;
}