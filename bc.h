#ifndef PROJETLO21_BC_H
#define PROJETLO21_BC_H

#include "allstructure.h"

/**********
 *
 * @param base de connaissance BC
 * @param une règle
 * @return la BC modifée
 * ajoute récursivement la règle en queue de la bc
 */
BC ajoute_en_queue_BC(Regle* bc, Regle *regle);

/************
 *
 * @param base de connaissance BC
 * @return une règle
 * renvoi la règle en tête
 */
Regle *renvoitetebc(BC bc);


/************
 *
 * @return base de connaissance BC
 * crée et initialise la BC
 */
BC creer_BC();

/**********
 *
 * @param base de connaissance BC
 * permet d'afficher l'ensemble de la base de connaissance
 */
void consulter_toute_la_BC(BC bc);

/*********
 *
 * @param base de connaissance BC
 * @param base de fait BF
 * @param chaîne de caractère
 * permet d'accéder au menu de gestion de la base de connaissance
 */
void menu_BC(BC bc, BF bf, char nom[]);


/***********
 *
 * @param base de connaissance BC
 * @return la BC modifiée
 * permet d'accéder à l'interface permettant d'ajouter une règle à la BC
 */
BC ajout_regle_BC(BC bc);
/******
 *
 * @param bc
 * @param conclu
 * @return
 */
BC search_conclu_show(BC bc, char conclu[]);
/***********
 *
 * @param base de connaissance BC
 * permet d'accéder à l'interface permettant d'entrer la conclusion de la règle que l'on cherche
 */
void consulter_bc_regle(BC bc);


/*******
 *
 * @param base de connaissance BC
 * @param chaîne de caractère
 * @return la bc modifiée
 * cherche une conclusion égale à la chaîne de caractère dans toutes les conclusions de règle de la bc
 */

BC search_conclu_delete(BC bc, char conclu[]);

/***********
 *
 * @param base de connaissance BC
 * permet d'accéder à l'interface permettant d'entrer la conclusion de la règle que l'on cherche à supprimer
 */
BC supp_bc_regle(BC bc);
/***********
 *
 * @param le nombre de proposition
 * @param tableau contenant les chaînes de caractères
 * @param règle
 * @param conclusion
 * @return une règle créée à partir des données
 * crée une règle à partir des infos données pour les bases templates
 */
Regle *insertiondsr(int max, char* tableau[], Regle *regle, char* conclusion);



/*************
 *
 * @param base de connaissance BC
 * @param conclusion recherchée
 * @return 1 si la conclusion n'existe pas déja sinon 0
 * permet de vérifier si une règle comporte déjà la même conclusion
 */
int verification_conclusion_unique(BC bc, char conclusion[]);


#endif //PROJETLO21_BC_H
