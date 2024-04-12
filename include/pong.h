#ifndef PONG_H
#define PONG_H

#include <vector>

#include "circle.h"
#include "figure.h"

const int SCREEN_W = 1080, SCREEN_H = 720, FPS = 60;

class Pong {
    public:
        Pong();
        ~Pong();
        void Next();
        void Draw();
        void Add(Figure* PFigure);
        std::vector<Figure*> PFigures;
};

#endif