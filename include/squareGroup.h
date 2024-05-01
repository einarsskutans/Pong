#ifndef SQUAREGROUP_H
#define SQUAREGROUP_H

#include <vector>
#include "figure.h"

class SquareGroup : public Figure {
    public:
        SquareGroup();
        SquareGroup(std::vector<Figure*> pfigures, double pfiguresgapx, double pfiguresgapy, double px, double py, double pvelx, double pvely, double psizex, double psizey, Color pcolor, bool pmovabale, bool pdrawable);
        ~SquareGroup();
        void Draw();
        std::vector<Figure*> figures;
        double figuresgapx, figuresgapy;
};

#endif