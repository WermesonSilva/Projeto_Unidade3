#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"
#include "Class_cutVoxel.h"

CutVoxel::CutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void CutVoxel::draw(Sculptor &sculp) {
    sculp.cutVoxel(this->x, this->y, this->z);
}
