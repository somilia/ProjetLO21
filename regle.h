#ifndef PROJETLO21_REGLE_H
#define PROJETLO21_REGLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "allstructure.h"

/**********
 * rien en paramètre
 * @return une règle initialisée avec:
 * un pointeur sur une première proposition, sur son arbre et tous les autres champs initialisés à NULL ou 0
 */
Regle *creerRegle();


/*******
 *prend en parametre:
 * une règle
 * une chaîne de caractère
 * @return une règle
 * place la chaîne de caractère dans une proposition qui est pointé par regle->conclusion
 */
Regle *creerConclusion(Regle *, char*);

/*********
 *
 * @param une règle
 * @param chaîne de caractère (prop)
 * @return règle
 *
 * fonction appelant ajouteEnQueueRec et permet d'incrémenter le nombre d'élément de la règle de 1
 */
Regle *ajouteEnQueueRegle(Regle* regle, char *prop);



/*********
* @param une règle
 * @param chaîne de caractère
 * @return règle
 * ajout en tête d'une règle une proposition contenant la chaîne de caractère
 */
Proposition *ajouteEnTete(Regle*, char*);



/*********
 *
 * @param une règle
 * @param chaîne de caractère (prop)
 * @return règle
 *
 * fonction ajoutant récursivement une proposition en queue contenant la chaîne de caractère prop
 */
Proposition *ajouteEnQueueRec(Proposition *regle, char *nvProp);



/*********
* @param une règle
 * @param chaîne de caractère
 * @return règle
 * suppression de la tête d'une règle (une proposition)
 */
Regle *suppressionTeteRec(Regle*);




Regle *suppressionRec(Regle *, char*);





/***************
 * prend en paramètre :
 * une règle
 * affiche toutes les proposition de la liste chainée de proposition dont elle pointe
 */
void afficherRegle(Regle*);



bool rechercheRec(Proposition*, char*);
bool isEmpty(Regle*);
char* valeurTete(Regle*);
char* valeurQueue(Regle*);
void afficheListeRec(Proposition*);
Proposition *insertion(Proposition *, char);
void suppression(Regle*, char);


#endif //PROJETLO21_REGLE_H