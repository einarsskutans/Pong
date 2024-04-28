#include <iostream>

#include "include/util.h"

// Center
Center::Center() {
    std::cout << "\nDefault constructor called CENTER " << this;
}
Center::Center(double px, double py) {
    std::cout << "\nConstructor called CENTER" << this;
    x = px, y = py;
}
Center::~Center() {
    std::cout << "\nDestructor called CENTER " << this;
}

// Color
Color::Color() {
    std::cout << "\nDefault constructor called COLOR " << this;
}
Color::Color(int pr, int pg, int pb) {
    std::cout << "\nConstructor called COLOR " << this;
    r = pr, g = pg, b = pb;
}
Color::~Color() {
    std::cout << "\nDestructor called COLOR " << this;
}