#pragma once

//namespace AllegroBase;

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <memory>

#include "pong.h"
#include "circle.h"
#include "figure.h"
#include "physics.h"
#include "pong.h"
#include "square.h"
#include "util.h"
#include "squareGroup.h"

const int FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;
const Center SCREEN_SIZE(1080, 720);

class AllegroBase
{
public:
    AllegroBase();
    virtual ~AllegroBase();

    bool Init( int screenWidth, int screenHeight, int fps );
    void Destroy();
    void Run();
    void Exit();

    // See help for ALLEGRO_KEYBOARD_STATE
    bool IsPressed( int keycode );

    void FocusGraphicWin();

    virtual void Fps() = 0;
    virtual void Draw() = 0;
    virtual void OnKeyDown( const ALLEGRO_KEYBOARD_EVENT &keyboard ) {};
    virtual void OnKeyUp( const ALLEGRO_KEYBOARD_EVENT &keyboard ) {};

protected:
    ALLEGRO_DISPLAY *alDisplay_;
    ALLEGRO_EVENT_QUEUE *alEventQueue_;
    ALLEGRO_TIMER *alTimer_;
    bool pressedKeys_[ALLEGRO_KEY_MAX];

private:
    bool exit_;

};
