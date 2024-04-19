#include "AllegroApp.hpp"
#include "AllegroBase.hpp"
#include "../Factory/FigureFactory.hpp"
#include "../Factory/UserFigureFactory.hpp"
#include "../Classes/ScreenSaver.hpp"
#include "../Classes/GameFigure.hpp"
#include "../Classes/Physics.hpp"
#include "../Exception/LogicException.cpp"

#include <string>
#include <iostream>

using namespace std;
using namespace Factory;
using namespace Except;

namespace Allegro {

    AllegroApp::AllegroApp():
        AllegroBase()
    {
        srand( time(NULL));
        user = UserFigureFactory::Create();

        for (long i=0; i<10; i++) {
            if (i <5) ScreenSaver::GetScreenSaver().Add({FigureFactory::Create(FigureFactory::Circle)});
            else ScreenSaver::GetScreenSaver().Add({FigureFactory::Create(FigureFactory::Square)});
        }
    }

    AllegroApp::~AllegroApp()
    {
    }

    void AllegroApp::Fps()
    {
        /* USER FIGURE GAMEPLAY */

        long dx = 0;
        long dy = 0;
        if (IsPressed(ALLEGRO_KEY_DOWN)) dy = 5;
        if (IsPressed(ALLEGRO_KEY_UP)) dy = -5;
        if (IsPressed(ALLEGRO_KEY_LEFT)) dx = -5;
        if (IsPressed(ALLEGRO_KEY_RIGHT)) dx = 5;
        if (IsPressed(ALLEGRO_KEY_ESCAPE)) Exit();

        user->MoveBy(dx,dy);

        if (user->IsVisible()){
            try{
                ScreenSaver::GetScreenSaver().GameResult(user);
            }
            catch(const FigureFit &e) {
                try
                {
                    user->Kick();
                    cout << "You have " << user->GetHealth() << " lifes" << endl;
                }
                catch(const TheEnd $e1)
                {
                    Exit();
                }
            }
        }
        else user->CheckVisibility();

        /* INTERFACE */
        if (pressedKeys_[ALLEGRO_KEY_S]) {

                cout << "Enter figure parameters:" << endl << "Figure type:centerx;centery;speedx;speedy;side or radius;" << endl << endl;
                string s; cin >> s;

                string type;
                long data[5];

                long pos = s.find(":");
                type = s.substr(0,pos);
                pos += 1;

                long pos1;

                for (long i=0; i<5; i++) {
                    pos1 = s.find(";",pos);
                    istringstream is(s.substr(pos,pos1));
                    is >> data[i];
                    pos = pos1 + 1;
                }


                if (type == "Circle") {
                     ScreenSaver::GetScreenSaver().Add( {FigureFactory::Create(FigureFactory::Circle, true, data[4], data[0], data[1], data[2], data[3])});
                }
                else ScreenSaver::GetScreenSaver().Add( {FigureFactory::Create(FigureFactory::Square, true, data[4], data[0], data[1], data[2], data[3])});
            }
            else if (pressedKeys_[ALLEGRO_KEY_W]) {
                pressedKeys_[ALLEGRO_KEY_W] = false;
                ostringstream os;
                ScreenSaver::GetScreenSaver().ShowFigureList(os);
                string s = os.str();
                cout << s << endl << endl << endl;
            }
            else if(pressedKeys_[ALLEGRO_KEY_Q]) {
                pressedKeys_[ALLEGRO_KEY_Q] = false;
                map<string, SPFigure> sow;

                sow["NW"] = ScreenSaver::GetScreenSaver().Search(2);
                sow["NE"] = ScreenSaver::GetScreenSaver().Search(1);
                sow["SW"] = ScreenSaver::GetScreenSaver().Search(3);
                sow["SE"] = ScreenSaver::GetScreenSaver().Search(4);
                for_each(sow.begin(),sow.end(),[] (const pair<string,SPFigure> &f)
                {
                        if (f.second != NotFound) {
                            cout << f.second->GetCenter().x << " " << f.second->GetCenter().y << " " << f.first << endl;
                        }
                });
                cout << endl;
            }
            else if(pressedKeys_[ALLEGRO_KEY_P]) {
                pressedKeys_[ALLEGRO_KEY_P] = false;
                cout << ScreenSaver::GetScreenSaver().FindSquare('L') << endl;
                cout << ScreenSaver::GetScreenSaver().FindSquare('R');
                cout << endl << endl;
            }
            else if(pressedKeys_[ALLEGRO_KEY_O]) {
                pressedKeys_[ALLEGRO_KEY_O] = false;
                ScreenSaver::GetScreenSaver().Generator();
            }
            else if(pressedKeys_[ALLEGRO_KEY_L]) {
                pressedKeys_[ALLEGRO_KEY_L] = false;
                ScreenSaver::GetScreenSaver().ToFile();
            }
            else if(pressedKeys_[ALLEGRO_KEY_K]) {
                pressedKeys_[ALLEGRO_KEY_K] = false;
                ScreenSaver::GetScreenSaver().FromFile();
            }
            else if(pressedKeys_[ALLEGRO_KEY_X]) {
                pressedKeys_[ALLEGRO_KEY_X] = false;
                ScreenSaver::GetScreenSaver().MultiPle();
            }

        ScreenSaver::GetScreenSaver().Next();
    }

    void AllegroApp::Draw()
    {
        ScreenSaver::GetScreenSaver().Draw();
        user->Draw();
    }
}
