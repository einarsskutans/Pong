#include <algorithm>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/AllegroBase.hpp"

using namespace std;

class AllegroApp : public AllegroBase {
    public:
        void Fps() {
            Pong::GetInstance().Next();

            if (!Pong::GetInstance().gameRuns) {
                if (IsPressed(ALLEGRO_KEY_SPACE)) {
                    Pong::GetInstance().gameRuns = true;
                    if (dynamic_cast<SquareGroup*>(Pong::GetInstance().Figures[Pong::lifeSquares])->figures.size() < 1) {
                        Square *life = new Square(0, 0, 0, 0, 12, 12, Color(255, 255, 255), false, true);
                        dynamic_cast<SquareGroup*>(Pong::GetInstance().Figures[Pong::lifeSquares])->figures.push_back(life);
                    }
                }
                for (int i = ALLEGRO_KEY_1; i < ALLEGRO_KEY_9; i++) { // Cycles through keys 1-9 to select game lives
                    if (IsPressed(i)) {
                        Pong::GetInstance().SetMaxLives(i - 28 + 1);

                        
                        dynamic_cast<SquareGroup&>(*Pong::GetInstance().Figures[Pong::lifeSquares]).figures = {};
                        for (int i = 0; i < Pong::GetInstance().GetMaxLives(); i++) {
                            auto life = std::make_shared<Square>(new Square(0, 0, 0, 0, 12, 12, Color(255, 255, 255), false, true));
                            dynamic_cast<SquareGroup&>(*Pong::GetInstance().Figures[Pong::lifeSquares]).figures.push_back(life);
                        }
                    }
                }
            }

            if (Pong::GetInstance().gameRuns) {
                Pong::GetInstance().Figures[Pong::racketRight]->vel.y = 0;
                if (
                    IsPressed(ALLEGRO_KEY_DOWN) &&
                    Pong::GetInstance().Figures[Pong::racketRight]->pos.y + Pong::GetInstance().Figures[Pong::racketRight]->size.y/2 < Pong::GetInstance().Figures[Pong::playingArea]->pos.y + Pong::GetInstance().Figures[Pong::playingArea]->size.y/2
                    ) {
                    Pong::GetInstance().Figures[Pong::racketRight]->vel.y = 10;
                }
                if (
                    IsPressed(ALLEGRO_KEY_UP) &&
                    Pong::GetInstance().Figures[Pong::racketRight]->pos.y - Pong::GetInstance().Figures[Pong::racketRight]->size.y/2 > Pong::GetInstance().Figures[Pong::playingArea]->pos.y - Pong::GetInstance().Figures[Pong::playingArea]->size.y/2
                    ) {
                    Pong::GetInstance().Figures[Pong::racketRight]->vel.y = -10;
                }
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