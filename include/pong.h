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

        void SetMaxLives(int n);
        int GetMaxLives();

        std::vector<Figure*> Figures;
        std::vector<Color> Colors;
        enum FiguresIDs {
            playingArea,
            ball,
            racketLeft,
            racketRight,
            lifeSquares,
        };
        bool gameRuns = false;
    private:
        Pong();
        ~Pong();
        int maxLives = 1;
        int lives = maxLives;
        Center blackBorderSize;
        int score;
};

#endif