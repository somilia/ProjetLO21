#ifndef PROJETLO21_NEW_COMPARING_H
#define PROJETLO21_NEW_COMPARING_H

#include "allstructure.h"


/************
 *
 * @param arbre
 * @param bf
 * @return 1 si l'élément de la base de fait est présent dans l'arbre binaire
 */
bool correspondance2(arbreb arbre, BF bf);


/***********
 *
 * @param regle
 * @param bf
 * @return 1 si la règle est vrai
 */
bool comparaison2(Regle *regle, BF bf);


/************
 *
 * @param bc
 * @return la bc où le nombre de proposition vrai pour chaque règle à été réinitialisé à 0
 */
BC reinitialisation_bc(BC bc);


/********
 *
 * @param bc
 * @param bf
 * @return vrai si une règle vient de passer à vrai
 */
bool comparaison_bc_bf_partielle2(BC bc, BF bf);


/*********
 *
 * @param base de connaissance
 * @return une base de connaissance avec TOUTES les variables permettant la comparaison réinitialisée à l'état d'origine
 */
BC reinitialisation_complete_bc(BC bc);


/************
 *
 * @param bc
 * @param bf
 * relance une comparaison si il y a eut une nouvelle règle passée à vrai sinon termine la comparaison
 */
void menu_comparaison_automatique(BC bc, BF bf);


/******************
 *
 * @param base de fait bf
 * @param conclusion de la règle tab
 * @return vrai si la conclusion n'est pas déjà présente dans la base de fait
 */
bool verification_conclusion_non_presente(BF bf, char tab[]);


/***************
 *
 * @param bf
 * affiche la base initiale
 */
void bf_initial(BF bf);


/***************
 *
 * @param bf
 * affiche la base final
 */
void bf_final(BF bf);


/**********
 *
 * @param bf
 * @param compt
 * affiche récursivement la bf
 */
void presentation_bf(BF bf, int compt);

#endif //PROJETLO21_NEW_COMPARING_H