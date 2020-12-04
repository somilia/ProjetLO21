//
// Created by denis on 03/12/2020.
//

#include "BF.h"
#include "regle.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "consulter.h"

BF menuBf(BF bf){
    int choix=0;
    printf("Que voulez vous faire?\n\n");
    printf("1) consulter la base actuelle\n");
    printf("2) ajouter un fait\n");
    printf("3) suprimer la base\n");
    printf("4) suprimer un fait\n");
    scanf("%d",&choix);
    switch(choix){

            case 1 :
                consulterBf(bf);
                break;
            case 2:
                 ajoutBf( bf);

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

void consulterBf(BF bf){
    if (bf == NULL)
    {
        exit(EXIT_FAILURE);
    }else{

            Proposition *actuel = bf;
            printf("voici la base de fait : \n");
            while (actuel != NULL)
            {
                printf("%s -> ", actuel->valeur);
                actuel = actuel->suivant;
            }

    }
}

BF ajoutBf(BF bf){

    char fait[20];
    printf("que voulez vous ajouter ?");
   scanf("%s",fait);

    bf=ajouteEnQueRec(bf,fait);
    return bf;
}

BF suppBf(BF bf){

    if (bf->suivant==NULL){
        free(bf);
        return NULL;
    }else{
        bf=suppBf(bf->suivant);
        return(bf);

    }
}