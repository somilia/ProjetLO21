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
#include <ctype.h>
void menuBf(BC bc,BF bf) {
    int choix = 0;
    int conf = 0;
    while (choix != 5) {
        system("cls");
        printf("Que voulez vous faire?\n\n");
        printf("1) consulter la base actuelle\n");
        printf("2) ajouter un fait\n");
        printf("3) suprimer la base\n");
        printf("4) suprimer un fait\n");
        printf("5) retour");
        scanf("%d", &choix);

        switch (choix) {

            case 1 :
                consulterBf(bf);
                conitnuer();
                break;
            case 2:
                bf = ajoutBf(bf);
                conitnuer();

                break;
            case 3:
                conf = confirmation();
                if (conf == 1) {
                    bf = suppBf(bf);
                }
                conitnuer();

                break;
            case 4:
                bf = suppFait(bf);
                conitnuer();

                break;

            case 5:
                menuprincipale(bc, bf);
                break;
                /* case 6:

                     break;*/
            default:
                printf("entrer un choix valide");
                conitnuer();

                break;
        }
    }
}

BF creerBf(){
   BF bf=malloc(sizeof(BF));
    Proposition *proposition = malloc(sizeof(Proposition));

    if (bf == NULL || proposition == NULL) {
        exit(EXIT_FAILURE);
    }

    proposition->valeur[0]=0;
    //   proposition->valeur = "\0";
    proposition->suivant = NULL;
   bf = proposition;

    return bf;
}
void conitnuer(){
        int compt=0;
    while(compt==0) {
        printf("appuyer sur 1 pour continuer\n");
        scanf("%d",&compt);

    }
}
BF suppFait(BF bf){
    int i=0;
    char fait[20];
    system("cls");
    printf("que voulez vous supprimer ?\n");
    scanf("%s",fait);
    for(i=0;i<strlen(fait);i++){
        fait[i]=tolower(fait[i]);
    }

    bf=suppressionfait(bf,fait);
    return bf;
}

BF suppressionfait(BF bf,char fait[]){


    if(bf==NULL){
        printf("Cette element n'est pas dans la base\n");
        return bf;
    }else{
        if(strcmp(bf->suivant->valeur,fait)==0){
            Proposition *tempo=bf->suivant;
            bf->suivant=bf->suivant->suivant;
            free(tempo);
            printf("fait");
            char compt='\0';
            while(compt=='\0') {
                printf("appuyer pour continuer");
                scanf("%c",&compt);

            }
            return bf;
        }else{
            bf->suivant=suppressionfait(bf->suivant,fait);
        }
    }
}
int confirmation(){
    int choix=0;
    do {
        system("cls");
        printf("confirmez vous votre choix?\n 1) oui \n2) non\n");
        scanf("%d", &choix);
    }while(choix!= 1 && choix!=2);
    return choix;
}

void consulterBf(BF bf){
    if (bf == NULL)
    {
       printf("base vide\n");
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
    int choix=1;
    while(choix==1){
    printf("que voulez vous ajouter ?\n");
   scanf("%s",fait);

    bf=ajouteEnQueRec(bf,fait);
    printf("voulez vous ajouter un nouveau fait? appuyer sur 1 pour continuer");
    scanf("%d",&choix);
    }
    return bf;
}

BF suppBf(BF bf){//a verifier si ca suprime bien tous les élément

    if (bf->suivant==NULL){
        free(bf);
        return NULL;
    }else{
        bf=suppBf(bf->suivant);
        return(bf);

    }
}