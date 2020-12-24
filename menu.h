#ifndef PROJETLO21_MENU_H
#define PROJETLO21_MENU_H

#include "allstructure.h"
#include "bf.h"
#include "bc.h"

/**********
 * initialise toutes les variables importantes:
 * la base de connaissance
 * la base de fait
 * le  nom de l'utilisateur
 */
void initialisation();


/*********
 *
 * @param base de connaissance BC
 * @param base de fait BF
 * @param le nom d'utilisateur (chaîne de caractère)
 * permet d'acceder à tous les différents menus
 */
void menu_principale(BC bc, BF bf, char nom[]);




/*********
 *
 * @param base de connaissance BC
 * @param base de fait BF
 * @param le nom d'utilisateur (chaîne de caractère)
 * permet d'acceder à tous les différents menus
 */



/*********
 *
 * @param base de connaissance BC
 * @param base de fait BF
 * @param le nom d'utilisateur (chaîne de caractère)
 * permet d'accèder au menu communiquant avec un fichier pour récuperer ou déposer des données
 */
void menu_sauvegarde(BC bc, BF bf, char nom[]);

#endif //PROJETLO21_MENU_H