#ifndef PROJETLO21_FICHIER_H
#define PROJETLO21_FICHIER_H

/***********
 *
 * @param base de connaissance bc
 * @param règle
 * ajoute une règle du fichier à la base de connaissance
 * @return la base de connaissance avec la nouvelle règle
 */
BC ajout_regle_bc_fichier(BC bc, Regle *regle);


/**************
 *
 * @param règle
 * @param nom de l'utilisateur
 * permet de copier une base de connaissance dans les fichiers
 */
void ajout_regle_fichier(Regle *regle, char nom[]);


/**************
 *
 * @param base de connaissance bc
 * @param nom de l'utilisateur
 *
 * @return la base de connaissance avec toutes les règles
 */
BC initialisation_creation_bc(BC bc, char nom[]);

Proposition* supp_regle_premier(Proposition* propo);


#endif //PROJETLO21_FICHIER_H