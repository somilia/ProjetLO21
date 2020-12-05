#ifndef PROJETLO21_REGLE_H
#define PROJETLO21_REGLE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "allstructure.h"

#include "allstructure.h"


Regle *creerRegle();
Regle *creerConclusion(Regle *, char*);

Proposition *ajouteEnTete(Regle*, char*);
Proposition *ajouteEnQueRec(Proposition*, char tab[]);

Regle *suppressionTeteRec(Regle*);
Regle *suppressionRec(Regle *, char*);

void afficherRegle(Regle*);

bool rechercheRec(Proposition*, char*);

bool isEmpty(Regle*);
char* valeurTete(Regle*);
char* valeurQueue(Regle*);

void afficheListeRec(Proposition*);
Proposition *insertion(Proposition *, char);
void suppression(Regle*, char);


#endif //PROJETLO21_REGLE_H


