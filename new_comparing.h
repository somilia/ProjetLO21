#ifndef PROJETLO21_NEW_COMPARING_H
#define PROJETLO21_NEW_COMPARING_H

#include "allstructure.h"

bool correspondance2(arbreb arbre, BF bf);
bool comparaison2(Regle *regle, BF bf);
BC reinitialisation_bc(BC bc);
bool comparaison_bc_bf_partielle2(BC bc, BF bf);

/*********
 *
 * @param base de connaissance
 * @return une base de connaissance avec TOUTES les variables permettant la comparaison réinitialisée à l'état d'origine
 */
BC reinitialisation_complete_bc(BC bc);

void menu_comparaison_automatique(BC bc, BF bf);

/******************
 *
 * @param base de fait bf
 * @param conclusion de la règle tab
 * @return vrai si la conclusion n'est pas déja présente dans la base de fait
 */
bool verification_conclusion_non_presente(BF bf, char tab[]);


#endif //PROJETLO21_NEW_COMPARING_HH