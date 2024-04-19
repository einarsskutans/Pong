#ifndef ALLEGROAPP_H
#define ALLEGROAPP_H

#include "AllegroBase.hpp"
#include "../Classes/ScreenSaver.hpp"
#include "../Classes/GameFigure.hpp"
#include <bits/stdc++.h>

using namespace Classes;

namespace Allegro {

    class AllegroApp : public AllegroBase
    {
    private:
        std::shared_ptr<GameFigure> user;
    public:
        AllegroApp();
        virtual ~AllegroApp();
        virtual void Fps();
        virtual void Draw();
    };
}

#endif // ALLEGROAPP_H
