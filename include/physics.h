#ifndef PHYSICS_H
#define PHYSICS_H

#include "figure.h"

class Physics {
    public:
        void static CollideBounds(std::shared_ptr<Figure> figure);
        void static CollideInnerBounds(std::shared_ptr<Figure> figure1, std::shared_ptr<Figure> figure2);
        bool static CollideCheck(std::shared_ptr<Figure> figure1, std::shared_ptr<Figure> figure2);

        void static RacketFollowBall(std::shared_ptr<Figure> figure1, std::shared_ptr<Figure> figure2, std::shared_ptr<Figure> figure3);
        void static Anchor(std::shared_ptr<Figure> figure1, std::shared_ptr<Figure> figure2);
};

#endif