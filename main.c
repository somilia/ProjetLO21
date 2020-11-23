#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "regle.h"

int main() {

    Regle test;
    test = creerRegle();
    afficherRegle(test);

    test = suppressionTeteRec(test);
    afficherRegle(test);
    printf("isEmpty: %d\n", isEmpty(test));

    test= ajouteEnQueRec(test,'A');
    afficherRegle(test);
    test = ajouteEnQueRec(test, 'B');
    afficherRegle(test);

    test = ajouteEnQueRec(test, 'C');
    afficherRegle(test);

    printf("la valeur de la tete: %c\n", valeurTete(test));
    printf("la valeur de la queue: %c\n", valeurQueue(test));
    printf("La proposition B appartient t-elle a la premissse: %d\n", rechercheRec(test, 'B'));
    test = ajouteEnQueRec(test,'K');
    afficherRegle(test);

    test = ajouteEnQueRec(test, 'D');
    afficherRegle(test);

    test = suppressionRec(test, 'K');
    afficherRegle(test);

    printf("isEmpty: %d\n", isEmpty(test));

    //  afficherRegle((Regle*)recherche_rec(test->premier, 'K'));

    return 0;
}
