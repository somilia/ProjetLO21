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
void initialisation(){
    BC bc=creerBC();
    BF bf=creerBf();
    menuprincipale(bc,bf);
}
void menuprincipale(BC bc,BF bf){
    int choix=0;

    while(choix<1 || choix>6) {
        printf("*************Bienvenue****************");
        printf("\n\n\nque voulez vous faire : \n");
        printf("1) menu base de connaissance\n");
        printf("2) menu base de faits\n");
        printf("3) lire une regle\n");
        printf("5)tester base de faits\n");
        printf("6)quitter\n");
        scanf("%d", &choix);
    }
    switch (choix){
        case 1 :
            menuBC(bc,bf);
            break;
        case 2:
            menuBf(bc,bf);
            break;
        case 3:
            lirereglechoisis(bc);
            break;
        case 4:

            break;

        case 5:

            break;
        case 6:

            break;

    }




}