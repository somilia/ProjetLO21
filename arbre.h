//
// Created by denis on 06/12/2020.
//

#ifndef PROJETLO21_ARBRE_H
#define PROJETLO21_ARBRE_H
#include "allstructure.h"
#include "BF.h"
#include "regle.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "consulter.h"
#include <ctype.h>
#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "allstructure.h"
#include "testbase.h"
typedef struct elem{
    Proposition * propo;
    struct elem* fg;
    struct elem* fd;
}noeud;

typedef noeud *arbreb;

arbreb enraciner(arbreb a1,arbreb a2,int e);
arbreb creerarbre_complet(arbreb arbre, Proposition *r);
noeud *creerFeuille(Proposition *p);
arbreb creerarbre();
arbreb inserer_regle_arbre(arbreb arbre, Proposition *r);

//PROJETLO21_ARBRE_H
