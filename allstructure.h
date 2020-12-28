#ifndef PROJETLO21_ALLSTRUCTURE_H
#define PROJETLO21_ALLSTRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "allstructure.h"

typedef struct proposition
{
    char valeur[20];
    struct proposition* suivant;
}Proposition;

typedef struct elem{
    char propo[20];
    struct elem* fg;
    struct elem* fd;
}noeud;

typedef noeud *arbreb;

typedef struct regle
{
    Proposition * premier;    // pointeur sur la première proposition
    Proposition * conclusion; // pointeur sur la conclusion
    struct regle* suivant;    // règle suivante
    arbreb arbre;             // pointeur sur l'arbre
    int nbpropo;              // le nombre de proposition
    int nbpropovrai;          // le nombre de proposition considéré comme vrai
    bool reponse;             // vaut 1 si la règle est vrai
}Regle;

typedef Proposition* BF;
typedef Regle* BC;


#endif //PROJETLO21_ALLSTRUCTURE_H