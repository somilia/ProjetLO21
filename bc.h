#ifndef PROJETLO21_BC_H
#define PROJETLO21_BC_H
#include "regle.h"


typedef Regle* BC;
Regle *ajouteEnQueBc(Regle* bc,  Proposition *regle);
Regle *renvoitetebc(BC bc);
BC creerBC();
BC *restebc(BC bc);

void initBC(BC);



#endif //PROJETLO21_BC_H
