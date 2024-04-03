#include "include/figure.h"

void Figure::Move() {
    pos.x = pos.x + vel.x;
    pos.y = pos.y + vel.y;
}