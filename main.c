#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "consulter.h"
#include "bf.h"
#include "menu.h"
#include "bc.h"
#include "regle.h"
#include "bf.h"
#include "menu.h"

#include "regle.h"
#include "bc.h"
#include "allstructure.h"
int main() {

  /*  Regle *test;
    test = creerRegle("fievre");
    afficherRegle(test);

    test = suppressionTeteRec(test);
    afficherRegle(test);
    printf("isEmpty: %d\n", isEmpty(test));

    test->premier = ajouteEnQueRec(test->premier, "A");
    afficherRegle(test);
    test->premier = ajouteEnQueRec(test->premier, "B");
    afficherRegle(test);

    test->premier = ajouteEnQueRec(test->premier, "C");
    afficherRegle(test);

    printf("la valeur de la tete: %s\n", valeurTete(test));
    printf("la valeur de la queue: %s\n", valeurQueue(test));
    printf("La proposition B appartient t-elle a la premisse: %d\n", rechercheRec(test->premier, "B"));
    test->premier = ajouteEnQueRec(test->premier, "K");
    afficherRegle(test);

    test->premier = ajouteEnQueRec(test->premier, "D");
    afficherRegle(test);

    // La fonction plante
  //  test = suppressionRec(test, "K");
    afficherRegle(test);

    test->premier = ajouteEnTete(test, "Z");
    afficherRegle(test);

    printf("isEmpty: %d\n", isEmpty(test));


    printf("\nTest de la BC:\n");

    BC bc = creer_BC();
    bc=initBC(bc);

    afficherRegle(bc);
printf("teste");
  //  Regle *test2;
  //  test2 = creerRegle("toux");
  //  test2->premier = ajouteEnQueueRec(test2->premier, "B");

  //  bc = ajoute_en_queue_BC(bc , test2->premier);
  //  test2=renvoitetebc(bc);
  consulter_liste_regle(bc,0);
     consulter_regle_choisi("grippe", bc);
*/
    /*BF bf=malloc(sizeof(*bf));
    bf->valeur[0]=0;
    //bf=ajout_Bf(bf);
   bf= ajouteEnQueRec(bf,"zizi");
    bf=ajouteEnQueRec(bf,"lour");
    bf=ajouteEnQueueRec(bf,"cassee");
    consulterBf(bf);
    bf=suppression_fait(bf,"lour");

    consulter_Bf(bf);*/

    initialisation();
    return 0;
}