#ifndef CIRCLEGROUP_H
#define CIRCLEGROUP_H

#include <vector>
#include "figure.h"

class CircleGroup : public Figure {
    public:
        CircleGroup();
        CircleGroup(std::vector<Figure*> pfigures, double pfiguresgapx, double pfiguresgapy, double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovabale, bool pdrawable);
        ~CircleGroup();
        void Draw();
        std::vector<Figure*> figures;
        double figuresgapx, figuresgapy;
};

#endif