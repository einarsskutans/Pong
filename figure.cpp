#include "include/figure.h"
#include "include/physics.h"

void Figure::Move() {
    Physics::CollideBounds(this);
    pos.x += vel.x;
    pos.y += vel.y;
}