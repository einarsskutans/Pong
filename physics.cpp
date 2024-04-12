#include "include/physics.h"
#include "include/figure.h"

void Physics::CollideBounds(Figure* figure) {
    
    if (figure->pos.y > SCREEN_H - figure->size.y/2 || figure->pos.y < 0 + figure->size.y/2) {
        figure->vel.y = -figure->vel.y;
    }
    if (figure->pos.x > SCREEN_W - figure->size.x/2 || figure->pos.x < 0 + figure->size.x/2) {
        figure->vel.x = -figure->vel.x;
    }
}