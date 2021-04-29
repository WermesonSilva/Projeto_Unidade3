#ifndef CLASS_CUTELLIPSOID_H_INCLUDED
#define CLASS_CUTELLIPSOID_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica {
    int cx, cy, cz, rx, ry, rz;
public:
    CutEllipsoid(int cx, int cy, int cz, int rx, int ry, int rz);
    ~CutEllipsoid() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_CUTELLIPSOID_H_INCLUDED
