#ifndef PHYSICS_H
#define PHYSICS_H

#include "figure.h"
#include "pong.h"

class Physics {
    public:
        void static CollideBounds(Figure* figure);
};

#endif