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
void Physics::InnerBounds(Figure* figure1, Figure* figure2) { // Bounds from inside another shape
    if (figure1->pos.y > (figure2->pos.y+figure2->size.y/2) - figure1->size.y/2 || figure1->pos.y < (figure2->pos.y-figure2->size.y/2) + figure1->size.y/2) {
        figure1->vel.y = -figure1->vel.y;
    }
    if (figure1->pos.x > (figure2->pos.x+figure2->size.x/2) - figure1->size.x/2 || figure1->pos.x < (figure2->pos.x-figure2->size.x/2) + figure1->size.x/2) {
        figure1->vel.x = -figure1->vel.x;
    }
}