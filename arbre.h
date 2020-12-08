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
int comparaison(arbreb arbre,BF bf);
void comparaison_bc_bf_parielle(BC bc, BF bf);
int nb_propo_bf(BF bf, int compt);
int comparaison_absolue(BC bc,BF bf);
void comparaison_bc_bf_strict(BC bc, BF bf);
void menu_comparaison(BC bc,BF bf);



#endif//PROJETLO21_ARBRE_H
