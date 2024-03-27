#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int SCREEN_W = 1080, SCREEN_H = 720, FPS = 30;

void fps() {
    
}

void draw() {
    
}

int main(int argc, char **argv) {
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