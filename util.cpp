#include <iostream>

#include "include/util.h"

// Center
Center::Center() {
    std::cout << "\nDefault constructor called " << this;
}
Center::Center(int px, int py) {
    std::cout << "\nConstructor called " << this;
    x = px, y = py;
}
Center::~Center() {
    std::cout << "\nDestructor called " << this;
}

// Color
Color::Color() {
    std::cout << "\nDefault constructor called " << this;
}
Color::Color(int pr, int pg, int pb) {
    std::cout << "\nConstructor called " << this;
    r = pr, g = pg, b = pb;
}
Color::~Color() {
    std::cout << "\nDestructor called " << this;
}