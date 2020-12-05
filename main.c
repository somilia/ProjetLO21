#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "consulter.h"
#include "BF.h"
#include "menu.h"
#include "bc.h"
#include "regle.h"
#include "BF.h"
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

    BC bc = creerBC();
    bc=initBC(bc);

    afficherRegle(bc);
printf("teste");
  //  Regle *test2;
  //  test2 = creerRegle("toux");
  //  test2->premier = ajouteEnQueRec(test2->premier, "B");

  //  bc = ajouteEnQueBc(bc , test2->premier);
  //  test2=renvoitetebc(bc);
  consulterlisteRegle(bc,0);
     consulterreglechoisi("grippe", bc);
*/
    /*BF bf=malloc(sizeof(*bf));
    bf->valeur[0]=0;
    //bf=ajoutBf(bf);
   bf= ajouteEnQueRec(bf,"zizi");
    bf=ajouteEnQueRec(bf,"lour");
    bf=ajouteEnQueRec(bf,"cassee");
    consulterBf(bf);
    bf=suppressionfait(bf,"lour");

    consulterBf(bf);*/
    initialisation();
    return 0;
}