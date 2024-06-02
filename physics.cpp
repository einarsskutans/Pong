#include "include/AllegroBase.hpp"

void Physics::CollideBounds(Figure* figure) {
    
    if (figure->GetPos().y > SCREEN_H - figure->GetSize().y/2 || figure->GetPos().y < 0 + figure->GetSize().y/2) {
        figure->SetVel({figure->GetVel().x, -figure->GetVel().y});
    }
    if (figure->GetPos().x > SCREEN_W - figure->GetSize().x/2 || figure->GetPos().x < 0 + figure->GetSize().x/2) {
        figure->SetVel({-figure->GetVel().x, figure->GetVel().y});
    }
}
void Physics::CollideInnerBounds(Figure* figure1, Figure* figure2) { // Bounds from inside another shape
    if (figure1->GetPos().y > (figure2->GetPos().y+figure2->GetSize().y/2) - figure1->GetSize().y/2 || figure1->GetPos().y < (figure2->GetPos().y-figure2->GetSize().y/2) + figure1->GetSize().y/2) {
        figure1->SetVel({figure1->GetVel().x, -figure1->GetVel().y});
    }
    if (figure1->GetPos().x > (figure2->GetPos().x+figure2->GetSize().x/2) - figure1->GetSize().x/2 || figure1->GetPos().x < (figure2->GetPos().x-figure2->GetSize().x/2) + figure1->GetSize().x/2) {
        figure1->SetVel({-figure1->GetVel().x, figure1->GetVel().y});
    }
}
bool Physics::CollideCheck(Figure* figure1, Figure* figure2) {
    if (
        figure1->GetPos().x + figure1->GetSize().x/2 >= figure2->GetPos().x - figure2->GetSize().x/2 &&
        figure1->GetPos().x - figure1->GetSize().x/2 <= figure2->GetPos().x + figure2->GetSize().x/2 &&
        figure1->GetPos().y + figure1->GetSize().y/2 >= figure2->GetPos().y - figure2->GetSize().y/2 &&
        figure1->GetPos().y - figure1->GetSize().y/2 <= figure2->GetPos().y + figure2->GetSize().y/2
    ) {
        return true;
    }
    return false;
}

void Physics::RacketFollowBall(Figure* figure1, Figure* figure2, Figure* figure3) {
    if ( // Racket's GetPos().y is attached directly to ball's GetPos().y, horrendous algorithm
        figure1->IsMovable() &&
        figure2->GetPos().y < figure3->GetPos().y+figure3->GetSize().y/2 - figure1->GetSize().y/2 && 
        figure2->GetPos().y > figure3->GetPos().y-figure3->GetSize().y/2 + figure1->GetSize().y/2
    ) {
        figure1->SetPos({figure1->GetPos().x, figure2->GetPos().y});
    }
}
void Physics::Anchor(Figure* figure1, Figure* figure2) {
    if (figure1->IsMovable()) {
        figure1->SetPos(figure2->GetPos());
        figure1->SetVel(figure2->GetVel());
    }
}