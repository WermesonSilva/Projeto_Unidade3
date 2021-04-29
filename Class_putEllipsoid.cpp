#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"
#include "Class_putEllipsoid.h"

PutEllipsoid::PutEllipsoid(int cx, int cy, int cz, int rx, int ry, int rz,
             float r, float g, float b, float a) {
    this->cx = cx;
    this->cy = cy;
    this->cz = cz;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutEllipsoid::draw(Sculptor &sculp) {
    sculp.setColor(this->r, this->g, this->b, this->a);
    sculp.putEllipsoid(this->cx, this->cy, this->cz, this->rx, this->ry, this->rz);
}
