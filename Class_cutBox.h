#ifndef CLASS_CUTBOX_H_INCLUDED
#define CLASS_CUTBOX_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class CutBox : public FiguraGeometrica {
private:
    int x0, x1, y0, y1, z0, z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_CUTBOX_H_INCLUDED
