#ifndef PROJETLO21_REGLE_H
#define PROJETLO21_REGLE_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Proposition Proposition;
struct Proposition
{
    char valeur;
    Proposition *suivant;
};

typedef struct Regle Regle;
struct Regle
{
    Proposition *premier;
};

Regle *creerRegle();
Proposition *creerConclusion(Regle*, char);

Proposition *ajouteEnTete(Regle*, char);
Proposition *ajouteEnQueRec(Proposition*, char);

Regle *suppressionTeteRec(Regle*);
Regle *suppressionRec(Regle *, char);

void afficherRegle(Regle*);

bool rechercheRec(Proposition*, char);

bool isEmpty(Regle*);
char valeurTete(Regle*);
char valeurQueue(Regle*);

void afficheListeRec(Proposition*);
Proposition *insertion(Proposition *, char);
void suppression(Regle*, char);


#endif //PROJETLO21_REGLE_H
