#include <iostream>
#include <fstream>
#include "classe_Sculptor.h"
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];
    for (int cont1 = 0; cont1 < nx; cont1++) {
        v[cont1] = new Voxel*[ny];
    }
    for (int cont1 = 0; cont1 < nx; cont1++) {
        for (int cont2 = 0; cont2 < ny; cont2++) {
            v[cont1][cont2] = new Voxel[nz];
        }
    }
}

Sculptor::~Sculptor() {
    for (int cont1 = 0; cont1 < nx; cont1++) {
        for (int cont2 = 0; cont2 < ny; cont2++) {
            delete [] v[cont1][cont2];
        }
    }
    for (int cont1 = 0; cont1 < nx; cont1++) {
        delete [] v[cont1];
    }
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if ((this->nx >= x) && (this->ny >= y) && (this->nz >= z)) {
        this->v[x][y][z].isOn = true;
        this->v[x][y][z].r = this->r;
        this->v[x][y][z].g = this->g;
        this->v[x][y][z].b = this->b;
        this->v[x][y][z].a = this->a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if ((this->nx >= x) && (this->ny >= y) && (this->nz >= z)) {
        this->v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int vx = x0; vx <= x1; vx++) {
        for (int vy = y0; vy <= y1; vy++) {
            for (int vz = z0; vz <= z1; vz++) {
                if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                    this->v[vx][vy][vz].isOn = true;
                    this->v[vx][vy][vz].r = this->r;
                    this->v[vx][vy][vz].g = this->g;
                    this->v[vx][vy][vz].b = this->b;
                    this->v[vx][vy][vz].a = this->a;
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int vx = x0; vx <= x1; vx++) {
        for (int vy = y0; vy <= y1; vy++) {
            for (int vz = z0; vz <= z1; vz++) {
                if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                    this->v[vx][vy][vz].isOn = false;
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {

    for (int vx = 0; vx < this->nx; vx++) {
        int xrai = (vx-xcenter) * (vx-xcenter); //(x - a) ^ 2 = (x - a) (x - a)
        for (int vy = 0; vy < this->ny; vy++) {
            int yrai = (vy-ycenter) * (vy-ycenter); //(y - b) ^ 2 = (y - b) (y - b)
            for (int vz = 0; vz < this->nz; vz++) {
                int zrai = (vz-zcenter) * (vz-zcenter); //(z - c) ^ 2 = (z - c) (z - c)

                if ( (xrai + yrai + zrai) <= (radius * radius) ) {
                    if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                        this->v[vx][vy][vz].isOn = true;
                        this->v[vx][vy][vz].r = this->r;
                        this->v[vx][vy][vz].g = this->g;
                        this->v[vx][vy][vz].b = this->b;
                        this->v[vx][vy][vz].a = this->a;
                    }
                }

            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {

    for (int vx = 0; vx < this->nx; vx++) {
        int xrai = (vx-xcenter) * (vx-xcenter);
        for (int vy = 0; vy < this->ny; vy++) {
            int yrai = (vy-ycenter) * (vy-ycenter);
            for (int vz = 0; vz < this->nz; vz++) {
                int zrai = (vz-zcenter) * (vz-zcenter);

                if ( (xrai + yrai + zrai) <= (radius * radius) ) {
                    if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                        this->v[vx][vy][vz].isOn = false;
                    }
                }

            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    for (int vx = 0; vx < this->nx; vx++) {
        double xrai = ( ((double) (vx - xcenter) *  (double) (vx - xcenter)) / ((double) rx * rx) );
        for (int vy = 0; vy < this->ny; vy++) {
            double yrai = ( ((double) (vy - ycenter) *  (double) (vy - ycenter)) / ((double) ry * ry) );
            for (int vz = 0; vz < this->nz; vz++) {
                double zrai = ( ((double) (vz - zcenter) *  (double) (vz - zcenter)) / ((double) rz * rz) );

                if ( (xrai + yrai + zrai) <= 1) {
                    if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                        this->v[vx][vy][vz].isOn = true;
                        this->v[vx][vy][vz].r = this->r;
                        this->v[vx][vy][vz].g = this->g;
                        this->v[vx][vy][vz].b = this->b;
                        this->v[vx][vy][vz].a = this->a;
                    }
                }

            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    for (int vx = 0; vx < this->nx; vx++) {
        double xrai = ( ((double) (vx - xcenter) *  (double) (vx - xcenter)) / ((double) rx * rx) );
        for (int vy = 0; vy < this->ny; vy++) {
            double yrai = ( ((double) (vy - ycenter) *  (double) (vy - ycenter)) / ((double) ry * ry) );
            for (int vz = 0; vz < this->nz; vz++) {
                double zrai = ( ((double) (vz - zcenter) *  (double) (vz - zcenter)) / ((double) rz * rz) );

                if ( (xrai + yrai + zrai) <= 1) {
                    if ((this->nx >= vx) && (this->ny >= vy) && (this->nz >= vz)) {
                        this->v[vx][vy][vz].isOn = false;
                    }
                }

            }
        }
    }
}

void Sculptor::writeOFF(char* filename) {
    ofstream arquivo;
    arquivo.open(filename);
    int qtd_blocs = 0;

    for (int vX = 0; vX < this->nx; vX++) {
        for (int vY = 0; vY < this->ny; vY++) {
            for (int vZ = 0; vZ < this->nz; vZ++) {
                if (this->v[vX][vY][vZ].isOn == true) {
                    qtd_blocs++;
                }
            }
        }
    }

    if (arquivo.is_open()) {
        arquivo << "OFF\n";
        arquivo << (qtd_blocs * 8) << " " << (qtd_blocs * 6) << " 0\n";

        //CORDENADAS DOS PONTOS
        for (int vX = 0; vX < this->nx; vX++) {
            for (int vY = 0; vY < this->ny; vY++) {
                for (int vZ = 0; vZ < this->nz; vZ++) {
                    if (this->v[vX][vY][vZ].isOn == true) {
                        arquivo << (-0.5 + vX) << " " << (0.5 + vY) << " " << (-0.5 + vZ) << "\n";
                        arquivo << (-0.5 + vX) << " " << (-0.5 + vY) << " " << (-0.5 + vZ) << "\n";
                        arquivo << (0.5 + vX) << " " << (-0.5 + vY)<< " " << (-0.5 + vZ) << "\n";
                        arquivo << (0.5 + vX) << " " << (0.5 + vY) << " " << (-0.5 + vZ) << "\n";
                        arquivo << (-0.5 + vX) << " " << (0.5 + vY) << " " << (0.5 + vZ) << "\n";
                        arquivo << (-0.5 + vX) << " " << (-0.5 + vY) << " " << (0.5 + vZ) << "\n";
                        arquivo << (0.5 + vX) << " " << (-0.5 + vY) << " " << (0.5 + vZ) << "\n";
                        arquivo << (0.5 + vX) << " " << (0.5 + vY) << " " << (0.5 + vZ) << "\n";
                    }
                }
            }
        }

        //DESIGNER DOS PONTOS
        qtd_blocs = 1;
        for (int vX = 0; vX < this->nx; vX++) {
            for (int vY = 0; vY < this->ny; vY++) {
                for (int vZ = 0; vZ < this->nz; vZ++) {
                    if (this->v[vX][vY][vZ].isOn == true) {
                        arquivo << "4 " << (0 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (3 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (2 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (1 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        arquivo << "4 " << (4 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (5 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (6 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (7 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        arquivo << "4 " << (0 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (1 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (5 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (4 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        arquivo << "4 " << (0 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (4 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (7 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (3 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        arquivo << "4 " << (3 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (7 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (6 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (2 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        arquivo << "4 " << (1 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (2 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (6 + (qtd_blocs - 1) * 8) << " ";
                        arquivo << (5 + (qtd_blocs - 1) * 8) << " ";
                        if (this->v[vX][vY][vZ].r == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].r == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].r << " ";
                        }
                        if (this->v[vX][vY][vZ].g == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].g == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].g << " ";
                        }
                        if (this->v[vX][vY][vZ].b == 0) {
                            arquivo << "0.0" << " ";
                        } else if (this->v[vX][vY][vZ].b == 1) {
                            arquivo << "1.0" << " ";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].b << " ";
                        }
                        if (this->v[vX][vY][vZ].a == 0) {
                            arquivo << "0.0" << "\n";
                        } else if (this->v[vX][vY][vZ].a == 1) {
                            arquivo << "1.0" << "\n";
                        }
                         else {
                            arquivo << this->v[vX][vY][vZ].a << "\n";
                        }

                        qtd_blocs++;

                    }
                }
            }
        }

        arquivo.close();
        cout << "Arquivo criado!";
    } else {
        cout << "Falha ao tentar abrir arquivo\n";
    }
}
