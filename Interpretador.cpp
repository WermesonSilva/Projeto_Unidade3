#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "classe_Sculptor.h"
#include "FiguraGeometrica.h"
#include "Class_putVoxel.h"
#include "Class_cutVoxel.h"
#include "Class_putBox.h"
#include "Class_cutBox.h"
#include "Class_putSphere.h"
#include "Class_cutSphere.h"
#include "Class_putEllipsoid.h"
#include "Class_cutEllipsoid.h"

#include "Interpretador.h"

void Interpretador::setDmx(int _dmx) {
    this->dmx = _dmx;
}
void Interpretador::setDmy(int _dmy) {
    this->dmy = _dmy;
}
void Interpretador::setDmz(int _dmz) {
    this->dmz = _dmz;
}

int Interpretador::getDmx(void) {
    return this->dmx;
}
int Interpretador::getDmy(void) {
    return this->dmy;
}
int Interpretador::getDmz(void) {
    return this->dmz;
}

std::vector<FiguraGeometrica*> Interpretador::traduza(char* raizarquivo) {
    std::ifstream arq_leitura;
    std::string comando;
    std::stringstream texto;
    std::vector<FiguraGeometrica*> figuras;

    arq_leitura.open(raizarquivo);
    if (arq_leitura.is_open()) {
        while (std::getline(arq_leitura, comando)) {
            texto.clear();
            texto.str(comando);
            texto >> comando;

            if (comando.compare("dim") == 0) {
                texto >> this->dmx;
                texto >> this->dmy;
                texto >> this->dmz;
            } else if (comando.compare("putvoxel") == 0) {
                int x, y, z;
                float r, g, b, a;

                texto >> x;
                texto >> y;
                texto >> z;
                texto >> r;
                texto >> g;
                texto >> b;
                texto >> a;

                figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));

            } else if (comando.compare("cutvoxel") == 0) {
                int x, y, z;

                texto >> x;
                texto >> y;
                texto >> z;

                figuras.push_back(new CutVoxel(x, y, z));

            } else if (comando.compare("putbox") == 0) {
                int x0, x1, y0, y1, z0, z1;
                float r, g, b, a;

                texto >> x0;
                texto >> x1;
                texto >> y0;
                texto >> y1;
                texto >> z0;
                texto >> z1;
                texto >> r;
                texto >> g;
                texto >> b;
                texto >> a;

                figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

            } else if (comando.compare("cutbox") == 0) {
                int x0, x1, y0, y1, z0, z1;

                texto >> x0;
                texto >> x1;
                texto >> y0;
                texto >> y1;
                texto >> z0;
                texto >> z1;

                figuras.push_back(new CutBox(x0, x1, y0, y1, z0,z1));

            } else if (comando.compare("putsphere") == 0) {
                int cx, cy, cz, radius;
                float r, g, b, a;

                texto >> cx;
                texto >> cy;
                texto >> cz;
                texto >> radius;
                texto >> r;
                texto >> g;
                texto >> b;
                texto >> a;

                figuras.push_back(new PutSphere(cx, cy, cz, radius, r, g, b, a));

            } else if (comando.compare("cutsphere") == 0) {
                int cx, cy, cz, radius;

                texto >> cx;
                texto >> cy;
                texto >> cz;
                texto >> radius;

                figuras.push_back(new CutSphere(cx, cy, cz, radius));

            } else if (comando.compare("putellipsoid") == 0) {
                int cx, cy, cz, rx, ry, rz;
                float r, g, b, a;

                texto >> cx;
                texto >> cy;
                texto >> cz;
                texto >> rx;
                texto >> ry;
                texto >> rz;
                texto >> r;
                texto >> g;
                texto >> b;
                texto >> a;

                figuras.push_back(new PutEllipsoid(cx, cy, cz, rx, ry, rz, r, g, b, a));

            } else if (comando.compare("cutellipsoid") == 0) {
                int cx, cy, cz, rx, ry, rz;

                texto >> cx;
                texto >> cy;
                texto >> cz;
                texto >> rx;
                texto >> ry;
                texto >> rz;

                figuras.push_back(new CutEllipsoid(cx, cy, cz, rx, ry, rz));

            }
        }
    } else {
        std::cout << "Erro ao abrir arquivo!\n";
    }

    return figuras;
}
