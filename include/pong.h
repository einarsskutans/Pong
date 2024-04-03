#ifndef PONG_H
#define PONG_H

#include <vector>

#include "circle.h"
#include "figure.h"

class Pong{
    public:
        Pong();
        Pong(int SCREEN_W, int SCREEN_H, int FPS);
        ~Pong();
        void Next();
        void Draw();
        void Add(Figure* PFigure);
        int SCREEN_W, SCREEN_H, FPS;
        std::vector<Figure*> PFigures;
};

#endif