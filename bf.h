#ifndef PROJETLO21_BF_H
#define PROJETLO21_BF_H

#include "allstructure.h"


void continuer();


/*********
 *
 * @param base de connaissance BC
 * @param base de fait BF
 * @param chaîne de caractère
 * permet d'acceder au menu de la base de fait
 */
void menu_Bf(BC bc, BF bf, char nom[]);

/************
 *
 * @param base de fait BF
 * permet d'afficher tous l'ensemble de la base de fait
 */
void consulter_Bf(BF bf);

/*******
 *
 * @param base de fait BF
 * @return base de fait modifiée
 * permet à l'utilisateur d'entrer un ou plusieurs faits
 */
BF ajout_Bf(BF bf);

/******************
 *
 * @param base de fait BF
 * @param chaîne de caractère tab
 * @return vrai si tab n'est pas deja contenu dans bf
 */
bool non_doublon_bf(BF bf, char tab[]);

/*******
*
* @param base de fait BF
* @return base de fait modifiée
* supprime l'ensemble des faits
*/
BF supp_Bf(BF bf);


/********
 *
 * @return un entier
 * permet de confirmer un choix
 */
int confirmation();

/********
 *
 * @param base de fait BF
 * @param chaîne de caractère
 * @return base de fait modifiés
 * suprime le fait correspondant
 */
BF suppression_fait(BF bf, char fait[]);

/*********
 *
 * @return la base de fait
 * initialise la base de fait
 */
BF creer_Bf();


/*******
*
* @param base de fait BF
* @return base de fait modifiée
* permet à l'utilisateur de supprimer un ou plusieurs faits
*/
BF supp_Fait(BF bf);


#endif //PROJETLO21_BF_H