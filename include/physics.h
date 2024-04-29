#ifndef PHYSICS_H
#define PHYSICS_H

#include "figure.h"

class Physics {
    public:
        void static CollideBounds(Figure* figure);
        void static CollideInnerBounds(Figure* figure1, Figure* figure2);
        bool static CollideCheck(Figure* figure1, Figure* figure2);

        void static RacketFollowBall(Figure* figure1, Figure* figure2, Figure* figure3);
        void static Anchor(Figure* figure1, Figure* figure2);
};

#endif