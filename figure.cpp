#include <iostream>

#include "include/figure.h"
#include "include/physics.h"

void Figure::Move(std::vector <Figure*> PFigures) {
    Physics::CollideInnerBounds(this, PFigures[0]);
    pos.x += vel.x;
    pos.y += vel.y;
}