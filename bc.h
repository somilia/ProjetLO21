#ifndef PROJETLO21_BC_H
#define PROJETLO21_BC_H
#include "regle.h"


typedef Regle* BC;
BC ajouteEnQueBc(Regle* bc,  Regle *regle);
Regle *renvoitetebc(BC bc);
BC creerBC();
BC *restebc(BC bc);
BC initBC(BC bc);

Regle *insertiondsr(int max ,char* tableau[],Regle *regle,char* conclucion);


#endif //PROJETLO21_BC_H
