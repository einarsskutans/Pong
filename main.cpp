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

class AllegroApp : public AllegroBase {
    public:
        void Fps() {
            Pong::GetInstance().Next();

            Pong::GetInstance().PFigures[Pong::racketRight]->vel.y = 0;
            if (
                IsPressed(ALLEGRO_KEY_DOWN) &&
                Pong::GetInstance().PFigures[Pong::racketRight]->pos.y + Pong::GetInstance().PFigures[Pong::racketRight]->size.y/2 < Pong::GetInstance().PFigures[Pong::playingArea]->pos.y + Pong::GetInstance().PFigures[Pong::playingArea]->size.y/2
                ) {
                Pong::GetInstance().PFigures[Pong::racketRight]->vel.y = 10;
            }
            if (
                IsPressed(ALLEGRO_KEY_UP) &&
                Pong::GetInstance().PFigures[Pong::racketRight]->pos.y - Pong::GetInstance().PFigures[Pong::racketRight]->size.y/2 > Pong::GetInstance().PFigures[Pong::playingArea]->pos.y - Pong::GetInstance().PFigures[Pong::playingArea]->size.y/2
                ) {
                Pong::GetInstance().PFigures[Pong::racketRight]->vel.y = -10;
            }
        }
        void Draw() {
            Pong::GetInstance().Draw();
        }
};

int main(int argc, char **argv) {
    srand( time(0) );
    AllegroApp app;
    if ( !app.Init( SCREEN_W, SCREEN_H, FPS ) ) {
        return 1;
    }
    app.Run();
    return 0;
}