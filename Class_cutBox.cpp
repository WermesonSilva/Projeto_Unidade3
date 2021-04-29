#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"
#include "Class_cutBox.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

void CutBox::draw(Sculptor &sculp) {
    sculp.cutBox(this->x0, this->x1, this->y0, this->y1, this->z0, this->z1);
}
