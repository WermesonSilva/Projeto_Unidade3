#ifndef CLASS_PUTVOXEL_H_INCLUDED
#define CLASS_PUTVOXEL_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class PutVoxel : public FiguraGeometrica {
private:
    int x, y, z;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_PUTVOXEL_H_INCLUDED
