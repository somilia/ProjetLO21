#ifndef PROJETLO21_BC_H
#define PROJETLO21_BC_H
#include "regle.h"


typedef Regle* BC;
Regle *ajouteEnQueBc(Regle* bc,  Proposition *regle);
Regle *renvoitetebc(BC bc);
BC creerBC();
BC *restebc(BC bc);
Regle *initBC(Regle* bc);

Regle *insertiondsr(int max ,char* tableau[],Regle *regle,char* conclucion);


#endif //PROJETLO21_BC_H
