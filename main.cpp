#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/figure.h"
#include "include/circle.h"
#include "include/util.h"
#include "include/pong.h"
using namespace std;

Center center(300, 200), vel(10, 10), dimensions(50,50);
Circle circle(center, vel, dimensions);
Pong pong(1080, 720, 60);

void fps() {
    pong.Next();
}

void draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    pong.Draw();
}

int main(int argc, char **argv) {
    pong.Add(&circle);

    srand(time(0));
    if(!InitAllegro(pong.SCREEN_W, pong.SCREEN_H, pong.FPS)) {
        DestroyAllegro();
        return 1;
    }

    al_set_window_title(alDisplay, "Pong");
    RunAllegro(&fps, &draw);
    DestroyAllegro();

    return 0;
}