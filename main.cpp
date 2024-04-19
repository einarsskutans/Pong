#include <iostream>
#include "include/AllegroBase.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/figure.h"
#include "include/circle.h"
#include "include/square.h"
#include "include/util.h"
#include "include/pong.h"
using namespace std;

class AllegroApp : AllegroBase {
    public:
        AllegroApp() {
            Pong* pong = new Pong();
        }

        void Fps() {
            pong.Next();
        }
        void Draw() {
            pong.Draw();
        }
    private:
        Pong* pong;
};



int main(int argc, char **argv) {
    srand(time(0));
    if(!pong.Init(SCREEN_W, SCREEN_H, FPS)) {
        DestroyAllegro();
        return 1;
    }
    al_set_window_title(alDisplay, "Pong");
    RunAllegro(&fps, &draw);
    AllegroBase::Run();
    DestroyAllegro();

    return 0;
}