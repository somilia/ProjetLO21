#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "regle.h"

int main() {

    Regle *test;
    test = creerRegle();
    afficherRegle(test);

    test->premier = suppressionTeteRec(test->premier);
    afficherRegle(test);
    printf("isEmpty: %d\n", isEmpty(test));

    test->premier = ajouteEnQueRec(test->premier,'A');
    afficherRegle(test);
    test->premier = ajouteEnQueRec(test->premier, 'B');
    afficherRegle(test);

    test->premier = ajouteEnQueRec(test->premier, 'C');
    afficherRegle(test);

    printf("la valeur de la tete: %c\n", valeurTete(test));
    printf("la valeur de la queue: %c\n", valeurQueue(test->premier));
    printf("La proposition B appartient t-elle a la premissse: %d\n", rechercheRec(test->premier, 'B'));
    test->premier = ajouteEnQueRec(test->premier,'K');
    afficherRegle(test);

    test->premier = ajouteEnQueRec(test->premier, 'D');
    afficherRegle(test);

    test->premier = suppressionRec(test->premier, 'K');
    afficherRegle(test);

    printf("isEmpty: %d\n", isEmpty(test));

    //  afficherRegle((Regle*)recherche_rec(test->premier, 'K'));

    return 0;
}
