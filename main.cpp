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

Pong* Pong::instance = nullptr;
Pong& pong = Pong::GetInstance();

void fps() {
    pong.Next();
}
void draw() {
    pong.Draw();
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