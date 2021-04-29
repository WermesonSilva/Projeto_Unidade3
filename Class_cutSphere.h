#ifndef CLASS_CUTSPHERE_H_INCLUDED
#define CLASS_CUTSPHERE_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica {
private:
    int cx, cy, cz, radius;
public:
    CutSphere(int cx, int cy, int cz, int radius);
    ~CutSphere() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_CUTSPHERE_H_INCLUDED
