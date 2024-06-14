#include <iostream>

#include "include/util.h"

// Center
Center::Center() {
}
Center::Center(double px, double py) {
    x = px, y = py;
}
Center::~Center() {
}

// Color
Color::Color() {
}
Color::Color(int pr, int pg, int pb) {
    r = pr, g = pg, b = pb;
}
Color::~Color() {
}

// Overloading operators
Center Center::operator+(const Center& center) {
    Center c;
    c.x = this->x + center.x;
    c.y = this->y + center.y;
    return c;
}
Center Center::operator/(const Center& center) {
    Center c;
    c.x = this->x / center.x;
    c.y = this->y / center.y;
    return c;
}
bool Center::operator<(const Center& center) {
    Center c;
    c.x = this->x / center.x;
    c.y = this->y / center.y;
}
