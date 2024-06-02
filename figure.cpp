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
Center Figure::GetPos() {
    return pos;
}
Center Figure::GetVel() {
    return vel;
}
Center Figure::GetSize() {
    return size;
}
void Figure::SetPos(Center ppos) {
    pos = ppos;
}
void Figure::SetVel(Center pvel) {
    vel = pvel;
}
void Figure::SetSize(Center psize) {
    size = psize;
}

bool Figure::IsMovable() {
    return movable;
}

bool Figure::IsDrawable() {
    return drawable;
}

void Figure::SetMovable(bool pmovable) {
    movable = pmovable;
}

void Figure::SetDrawable(bool pdrawable) {
    drawable = pdrawable;
}
