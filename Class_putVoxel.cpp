#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"
#include "Class_putVoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutVoxel::draw(Sculptor &sculp) {
    sculp.setColor(this->r, this->g, this->b, this->a);
    sculp.putVoxel(this->x, this->y, this->z);
}
