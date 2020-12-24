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
    Proposition * premier;
    Proposition * conclusion;
    struct regle* suivant;
    arbreb arbre;
    int nbpropo;
    int nbpropovrai;
    bool reponse;
}Regle;

typedef Proposition* BF;
typedef Regle* BC;


#endif //PROJETLO21_ALLSTRUCTURE_H