#ifndef SQUAREGROUP_H
#define SQUAREGROUP_H

#include <vector>
#include "figure.h"

class SquareGroup : public Figure {
    public:
        SquareGroup();
        SquareGroup(Center pfiguresgap, Center ppos, Center pvel, Center psize, Color pcolor, bool pmovabale, bool pdrawable);
        ~SquareGroup();
        void Draw();
        
        std::vector<Figure*> figures;
        Center figuresgap;
        Center GetFiguresgap();
        void SetFiguresgap(Center pfiguresgap);
};

#endif