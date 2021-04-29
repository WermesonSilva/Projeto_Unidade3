#ifndef CLASS_PUTSPHERE_H_INCLUDED
#define CLASS_PUTSPHERE_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class PutSphere : public FiguraGeometrica {
    int cx, cy, cz, radius;
public:
    PutSphere(int cx, int cy, int cz, int radius,
              float r, float g, float b, float a);
    ~PutSphere() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_PUTSPHERE_H_INCLUDED
