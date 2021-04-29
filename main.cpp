#include <iostream>
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

int main(void) {
    Sculptor *escultura;
    Interpretador interprete;
    std::vector<FiguraGeometrica*> figuras;

    figuras = interprete.traduza("C:\\Users\\swerm\\Desktop\\arquivos_txt\\comandos.txt");
    escultura = new Sculptor(interprete.getDmx(), interprete.getDmy(), interprete.getDmz());

    for (int x = 0; x < figuras.size(); x++) {
        figuras[x]->draw(*escultura);
    }

    escultura->writeOFF("C:\\Users\\swerm\\Desktop\\arquivos_txt\\teste001.off");

    for (int x = 0; x < figuras.size(); x++) {
        delete figuras[x];
    }

    delete escultura;

    return 0;
}
