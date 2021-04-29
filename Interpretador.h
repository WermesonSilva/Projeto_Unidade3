#ifndef INTERPRETADOR_H_INCLUDED
#define INTERPRETADOR_H_INCLUDED

#include "FiguraGeometrica.h"
#include <vector>

class Interpretador {
private:
    int dmx, dmy, dmz;
public:
    void setDmx(int _dmx);
    void setDmy(int _dmy);
    void setDmz(int _dmz);
    int getDmx(void);
    int getDmy(void);
    int getDmz(void);
    std::vector<FiguraGeometrica*> traduza(char* raizarquivo);
};

#endif // INTERPRETADOR_H_INCLUDED
