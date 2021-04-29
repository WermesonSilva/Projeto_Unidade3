#ifndef CLASS_CUTVOXEL_H_INCLUDED
#define CLASS_CUTVOXEL_H_INCLUDED

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica {
private:
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel() {

    }
    void draw(Sculptor &sculp);
};

#endif // CLASS_CUTVOXEL_H_INCLUDED
