#ifndef PROJETLO21_CONSULTER_H
#define PROJETLO21_CONSULTER_H

#include "allstructure.h"
#include "bc.h"

    /****************
     * les fonctions ici ne sont pas utilisé mais sont gardé sous la main au cas ou
     *
     *
     *
     *
     */




/********
 *
 * @param base de connaissance BC
 * @param 0   initialisé à 0 pour numéroter toutes les règles
 * affiche récursivement toutes les règles présentes dans la base de connaissance et les numérotes
 */
void consulter_liste_regle(BC bc, int compt);


/***********
 *
 * @param le nom de la conclusion de la règle : chaîne de caractère
 * @paramla base de connaissance BC
 * affiche la règle qui comporte cette conclusion si possible
 */
void consulter_regle_choisi(char nom[], BC bc);


/***************
 *
 * @param chaine de caractere
 * permet à l'utilisateur d'entrer le nom d'une règle qui sera convertit en minuscule
 */
void nom_regle_rechercher(char nomregle[]);

void lire_regle_choisi(BC bc);


#endif //PROJETLO21_CONSULTER_H