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
    char valeur[20];          // chaîne de caractère: nom de la proposition
    struct proposition* suivant;// pointeur sur la proposition suivante
}Proposition;

typedef struct elem{
    char propo[20];           // chaîne de caractère: nom de la proposition
    struct elem* fg;          // pointeur sur un noeud
    struct elem* fd;          // pointeur sur un noeud
}noeud;

typedef noeud *arbreb;        // pointeur sur un noeud

typedef struct regle
{
    Proposition * premier;    // pointeur sur le premier élément de la règle
    Proposition * conclusion; // pointeur sur la conclusion de la règle
    struct regle* suivant;    // pointeur sur la prochaine règle de la base de connaissance
    arbreb arbre;             // arbre binaire de la règle
    int nbpropo;              // nombre de proposition de la règle
    int nbpropovrai;          // nombre de proposition considéré comme vrai lors de la comparaison
    bool reponse;             // vrai si nous avons déjà evalué la règle comme vrai
}Regle;

typedef Proposition* BF;      // base de fait: pointeur sur une proposition
typedef Regle* BC;            // base de connaissance: pointeur sur règle


#endif //PROJETLO21_ALLSTRUCTURE_H