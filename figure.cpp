#include <iostream>

#include "include/figure.h"

void Figure::Move(double px, double py) {
    pos.x = px;
    pos.y = py;
}
void Figure::SetDefaultVel(Center pvel) {
    defaultVel = pvel;
}
void Figure::ResetVel() {
    vel = defaultVel;
}