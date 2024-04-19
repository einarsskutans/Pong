#ifndef PONG_H
#define PONG_H

#include <vector>

#include "AllegroBase.hpp"
#include "circle.h"
#include "figure.h"

class Pong {
    public:
        static Pong& GetInstance();
        void Next();
        void Draw();
        void Add(Figure* PFigure);
        std::vector<Figure*> PFigures;

    private:
        Pong();
        ~Pong();
        
};

#endif