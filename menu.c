//
// Created by denis on 02/12/2020.
//
#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "consulter.h"
#include "BF.h"
#include "allstructure.h"
#include "arbre.h"

void initialisation(){
    BC bc=creerBC();
    BF bf=creerBf();
    menuprincipale(bc,bf);
}
void menuprincipale(BC bc,BF bf){
    int choix=0;

    while(choix!=6) {
        system("cls");
        printf("*************Bienvenue****************");
        printf("\n\n\nque voulez vous faire : \n");
        printf("1) menu base de connaissance\n");
        printf("2) menu base de faits\n");
        printf("3) lire une regle\n");
        printf("5) tester la base de faits\n");
        printf("6) quitter\n");
        scanf("%d", &choix);

    switch (choix){
        case 1 :
            menuBC(bc,bf);
            break;
        case 2:
            menuBf(bc,bf);
            break;
        case 3:
            system("cls");
            consulter_bc_regle(bc);
            conitnuer();
            break;
        case 4:

            break;

        case 5:
            system("cls");

            menu_comparaison(bc,bf);
            conitnuer();

            break;
        case 6:
        afficher(bc->suivant->arbre);
            conitnuer();

            break;

    }
}



}