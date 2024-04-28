#ifndef PONG_H
#define PONG_H

#include <vector>

#include "AllegroBase.hpp"
#include "figure.h"

class Pong {
    public:
        static Pong& GetInstance();
        void Next();
        void Draw();
        void Add(Figure* Figure);

        std::vector<Figure*> Figures;
        std::vector<Color> Colors;
        int maxLives = 5;
        int lives = maxLives;
        enum FiguresIDs {
            playingArea,
            ball,
            racketLeft,
            racketRight,
        };
    private:
        Pong();
        ~Pong();
        
};

#endif