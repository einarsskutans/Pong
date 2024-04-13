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

Pong* pong = new Pong();

void fps() {
    pong->Next();
}
void draw() {
    pong->Draw();
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

    delete pong;
    return 0;
}