#include <iostream>

#include "include/pong.h"

Pong::Pong() {
    std::cout << "\nDefault constructor called " << this;
    SCREEN_W = 540;
    SCREEN_H = 450;
    FPS = 60;
}
Pong::Pong(int pSCREEN_W, int pSCREEN_H, int pFPS) {
    std::cout << "\nConstructor called " << this;
    SCREEN_W = pSCREEN_W;
    SCREEN_H = pSCREEN_H;
    FPS = pFPS;
}
Pong::~Pong() {
    std::cout << "\nDestructor called " << this;
}

void Pong::Next() {
    for (Figure* PFigure : PFigures) {
        PFigure->Move();
    }
}
void Pong::Draw() {
    for (Figure* PFigure : PFigures) {
        PFigure->Draw();
    }
}
void Pong::Add(Figure* PFigure) {
    PFigures.push_back(PFigure);
}
