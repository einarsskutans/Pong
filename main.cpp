#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/figure.h"
#include "include/circle.h"
#include "include/square.h"
#include "include/util.h"
#include "include/pong.h"
using namespace std;

Color white(255, 255, 255);
Color blueBorder(71, 147, 175);

Pong pong;
Circle circle(SCREEN_W/2, SCREEN_H/2, 10, 10, 10, 10, white);
Square square(SCREEN_W/8, SCREEN_H/8, 10, 10, 100, 100, blueBorder);

void fps() {
    pong.Next();
}

void draw() {
    pong.Draw();
}

int main(int argc, char **argv) {
    pong.Add(&circle);
    pong.Add(&square);
    srand(time(0));
    if(!InitAllegro(SCREEN_W, SCREEN_H, FPS)) {
        DestroyAllegro();
        return 1;
    }

    al_set_window_title(alDisplay, "Pong");
    RunAllegro(&fps, &draw);
    DestroyAllegro();

    return 0;
}