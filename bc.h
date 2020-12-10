#ifndef PROJETLO21_BC_H
#define PROJETLO21_BC_H
#include "regle.h"
#include "BF.h"
#include "newBC.h"
#include "allstructure.h"


BC ajouteEnQueBc(Regle* bc,  Regle *regle);
Regle *renvoitetebc(BC bc);
BC creerBC();
BC *restebc(BC bc);
BC initBC(BC bc);
void consultertoutelaBC(BC bc);
void menuBC(BC bc, BF bf);
BC ajoutregleBC(BC bc);
BC searchconclu_show(BC bc,char conclu[]);
void consulter_bc_regle(BC bc);
BC searchconclu_delete(BC bc,char conclu[]);
BC supp_bc_regle(BC bc);

Regle *insertiondsr(int max ,char* tableau[],Regle *regle,char* conclucion);
int verification_conclusion_unique(BC bc,char conclusion[]);


#endif //PROJETLO21_BC_H
