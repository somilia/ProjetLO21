#ifndef PROJETLO21_REGLE_H
#define PROJETLO21_REGLE_H
#include <stdio.h>
#include <stdlib.h>



typedef struct proposition
{
    char valeur;
    struct proposition* suivant;
}Proposition;

typedef Proposition* Regle;

Regle creerRegle();
Regle creerConclusion(Regle, char);

Regle ajouteEnTete(Regle, char);
Regle ajouteEnQueRec(Regle regle, char nvProp);
Regle suppressionTeteRec(Regle);
Regle suppressionRec(Regle , char);

void afficherRegle(Regle);

bool rechercheRec(Proposition*, char);

bool isEmpty(Regle);
char valeurTete(Regle);
char valeurQueue(Regle);

void afficheListeRec(Proposition);
Proposition *insertion(Proposition , char);
void suppression(Regle, char);
Regle reste(Regle regle);
Proposition creerProposition(char nvProp);

#endif //PROJETLO21_REGLE_H
