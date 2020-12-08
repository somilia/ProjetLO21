//
// Created by denis on 05/12/2020.
//

#ifndef PROJETLO21_ALLSTRUCTURE_H
#define PROJETLO21_ALLSTRUCTURE_H
#include "allstructure.h"


typedef struct proposition
{
    char valeur[20];
    struct proposition* suivant;
}Proposition;

//typedef Proposition* Regle;
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
}Regle;

typedef Proposition* BF;
typedef Regle* BC;

#endif //PROJETLO21_ALLSTRUCTURE_H
