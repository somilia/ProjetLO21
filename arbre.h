#ifndef PROJETLO21_ARBRE_H
#define PROJETLO21_ARBRE_H

#include "allstructure.h"

arbreb enraciner(arbreb a1,arbreb a2,int e);
/********
 *
 * @param un arbre
 * @param chaîne de caractère
 * @return un arbre
 * place la chaîne de caractère dans l'arbre binaire
 */
arbreb creer_arbre_complet(arbreb arbre, char *propo);

/********
 *
 * @param chaîne de caractère
 * @return un noeud
 * permet de creer une feuille contenant la proposition
 */
noeud *creer_feuille(char *propo);


/*********
 *
 * @return un arbre initialisé
 */
arbreb creer_arbre();


Regle* inserer_regle_arbre(BC bc, BF bf);
bool correspondance(arbreb arbre, BF bf);
void afficher(arbreb arbre);
bool comparaison(arbreb arbre, BF bf);
void comparaison_bc_bf_partielle(BC bc, BF bf);


/********
 *
 * @param base de fait
 * @param 0
 * @return le nombre de proposition dans la base de fait
 * compte récursivement le nombre de proposition dans la base de fait
 */
int nb_propo_bf(BF bf, int compt);


bool comparaison_absolue(BC bc, BF bf);
void comparaison_bc_bf_strict(BC bc, BF bf);
void menu_comparaison(BC bc, BF bf);



/******
 *
 * @param un arbre
 * supprime l'arbre
 */
void supprimer_arbre(arbreb arbre);


#endif//PROJETLO21_ARBRE_H