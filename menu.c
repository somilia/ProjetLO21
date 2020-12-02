//
// Created by denis on 02/12/2020.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"


void initialisation(){
    int choix=0;
    while(choix<1 || choix>6) {
        printf("*************Bienvenue****************");
        printf("\n\n\nque voulez vous faire : \n");
        printf("1) ajouter une base de connaissance");
        printf("2) creer une base de faits");
        printf("3) lire une regle");
        printf("4)lire une base de faits");
        printf("5)tester une base de faits");
        printf("6)quitter");
        scanf("%d", &choix);
    }
    switch (choix){
        case 1 :

            break;
        case 2:

            break;
        case 3:

        break;
        case 4:

            break;

        case 5:

            break;
        case 6:

            break;

    }




}