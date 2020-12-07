//
// Created by denis on 06/12/2020.
//

#ifndef PROJETLO21_ARBRE_H
#define PROJETLO21_ARBRE_H


#include "allstructure.h"

arbreb enraciner(arbreb a1,arbreb a2,int e);
arbreb creerarbre_complet(arbreb arbre,char propo[]);
noeud *creerFeuille(char propo[]);
arbreb creerarbre();
Regle* inserer_regle_arbre( BC bc,BF bf);
int corespondace(arbreb arbre,BF bf);
void afficher(arbreb arbre);
void comparaison(arbreb arbre,BF bf);



#endif//PROJETLO21_ARBRE_H
