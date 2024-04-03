#include <iostream>

#include "include/util.h"

Center::Center() {
    std::cout << "\nDefault constructor called " << this;
}
Center::Center(int px, int py) {
    std::cout << "\nConstructor called " << this;
    x = px;
    y = py;
}
Center::~Center() {
    std::cout << "\nDestructor called " << this;
}