#ifndef PROJETLO21_FICHIER_H
#define PROJETLO21_FICHIER_H

BC ajout_regle_bc_fichier(BC bc, Regle *regle);

Regle *supp_regle(Regle *regle);

void ajout_regle_fichier(Regle *regle, char nom[]);

BC initialisation_creation_bc(BC bc, char nom[]);

Proposition* supp_regle_premier(Proposition* propo);


#endif //PROJETLO21_FICHIER_H