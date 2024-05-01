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
        std::vector<Figure*> LivesFigures;
        enum FiguresIDs {
            playingArea,
            ring,
            ball,
            ball2,
            racketLeft,
            racketRight,
            lifeSquares,
        };
    private:
        Pong();
        ~Pong();
        Center blackBorderSize;
        int maxLives = 5;
        int lives = maxLives;
        int score;
};

#endif