#include "include/physics.h"
#include "include/figure.h"
#include "include/pong.h"

void Physics::CollideBounds(Figure* figure) {
    
    if (figure->pos.y > SCREEN_H - figure->size.y/2 || figure->pos.y < 0 + figure->size.y/2) {
        figure->vel.y = -figure->vel.y;
    }
    if (figure->pos.x > SCREEN_W - figure->size.x/2 || figure->pos.x < 0 + figure->size.x/2) {
        figure->vel.x = -figure->vel.x;
    }
}
void Physics::CollideInnerBounds(Figure* figure1, Figure* figure2) { // Bounds from inside another shape
    if (figure1->pos.y > (figure2->pos.y+figure2->size.y/2) - figure1->size.y/2 || figure1->pos.y < (figure2->pos.y-figure2->size.y/2) + figure1->size.y/2) {
        figure1->vel.y = -figure1->vel.y;
    }
    if (figure1->pos.x > (figure2->pos.x+figure2->size.x/2) - figure1->size.x/2 || figure1->pos.x < (figure2->pos.x-figure2->size.x/2) + figure1->size.x/2) {
        figure1->vel.x = -figure1->vel.x;
    }
}
bool Physics::CollideCheck(Figure* figure1, Figure* figure2) {
    if (
        figure1->pos.x + figure1->size.x/2 >= figure2->pos.x - figure2->size.x/2 &&
        figure1->pos.x - figure1->size.x/2 <= figure2->pos.x + figure2->size.x/2 &&
        figure1->pos.y + figure1->size.y/2 >= figure2->pos.y - figure2->size.y/2 &&
        figure1->pos.y - figure1->size.y/2 <= figure2->pos.y + figure2->size.y/2
    ) {
        return true;
    }
    return false;
}

void Physics::RacketFollowBall(Figure* figure1, Figure* figure2, Figure* figure3) {
    if ( // Racket's pos.y is attached directly to ball's pos.y, horrendous algorithm
        figure1->movable &&
        figure2->pos.y < figure3->pos.y+figure3->size.y/2 - figure1->size.y/2 && 
        figure2->pos.y > figure3->pos.y-figure3->size.y/2 + figure1->size.y/2
    ) {
        figure1->pos.y = figure2->pos.y;
}
}