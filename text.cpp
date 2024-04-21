#include <iostream>
#include "include/AllegroBase.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/text.h"

Text::Text() {
    std::cout << "\nDefault constructor called TEXT " << this;
}
Text::Text() {
    std::cout << "\nConstructor called TEXT " << this;
}
Text::~Text() {
    std::cout << "\nDestructor called TEXT " << this;
}
void Text::Draw() {
    //al_draw_text();
}