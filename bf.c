#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "allstructure.h"
#include "regle.h"
#include "bc.h"
#include "bf.h"
#include "arbre.h"
#include "menu.h"
#include "consulter.h"
#include "testbase.h"

void menu_Bf(BC bc, BF bf, char nom[]){

    int choix = 0;
    int conf = 0;
    while (choix != 5){
        system("cls");
        printf("Que voulez-vous faire ?\n\n");
        printf("1) Consulter la base actuelle\n");
        printf("2) Ajouter un fait\n");
        printf("3) Suprimer la base\n");
        printf("4) Suprimer un fait\n");
        printf("5) Retour");
        scanf("%d", &choix);

        switch (choix){

            case 1 :
                system("cls");
                consulter_Bf(bf);
                continuer();

                break;
            case 2:
                system("cls");
                bf = ajout_Bf(bf);
                continuer();

                break;
            case 3:
                system("cls");
                conf = confirmation();
                if (conf == 1){
                    bf = supp_Bf(bf);
                }
                continuer();

                break;
            case 4:
                system("cls");
                bf = supp_Fait(bf);
                continuer();

                break;
            case 5:
                system("cls");
                menu_principale(bc, bf, nom);

                break;
            /*case 6:

                break;*/
            default:
                printf("Entrer un choix valide ");
                continuer();

                break;
        }
    }
}

BF creer_Bf(){

    BF bf = malloc(sizeof(BF));
    Proposition *proposition = malloc(sizeof(Proposition));

    if (bf == NULL || proposition == NULL){
        exit(EXIT_FAILURE);
    }

    proposition->valeur[0] = ' ';
    proposition->suivant = NULL;
    bf = proposition;

    return bf;
}

void continuer(){

    int compt = 0;
    while(compt==0){
        printf("\nAppuyer sur 1 pour continuer :  \n");
        scanf("%d", &compt);
    }
}

BF supp_Fait(BF bf){

    int i = 0;
    char fait[20];
    system("cls");
    printf("Que voulez-vous supprimer ? :  \n");
    scanf("%s", fait);
    for(i=0;i<strlen(fait);i++){
        fait[i] = tolower(fait[i]);
    }
    bf = suppression_fait(bf, fait);
    return bf;
}

BF suppression_fait(BF bf, char fait[]){

    if(bf==NULL){
        printf("Cette element n'est pas dans la base\n");
        return bf;
    }else{
        if(strcmp(bf->valeur,fait)==0){
            Proposition *tempo = bf->suivant;
            bf = bf->suivant;
            free(tempo);
            printf("fait");
            char compt='\0';
            while(compt=='\0'){
                printf("Appuyer pour continuer");
                scanf("%c", &compt);
            }
            return bf;
        }else{
            bf->suivant = suppression_fait(bf->suivant, fait);
        }
    }
}

int confirmation(){

    int choix=0;
    do {
        system("cls");
        printf("Confirmez-vous votre choix?\n 1) Oui \n2) Non\n");
        scanf("%d", &choix);
    }while(choix!=1 && choix!=2);
    return choix;
}

void consulter_Bf(BF bf){

    if (bf == NULL){
        printf("Base vide\n");
    }else{
        if (bf->valeur[0] == ' '){
            printf("Base vide\n");
        }else{
            Proposition *actuel = bf;
            printf("Voici la base de fait : \n");
            while (actuel != NULL){
                printf("%s -> ", actuel->valeur);
                actuel = actuel->suivant;
            }
        }
    }
}

BF ajout_Bf(BF bf){
    char fait[20];
    int choix = 1;
    while(choix==1){
        printf("Que voulez-vous ajouter ? :  \n");
        scanf("%s", fait);
        if(non_doublon_bf(bf,fait)==true){
            bf = ajouteEnQueueRec(bf, fait);

        }else{
            printf("attention element deja present\n");
        }
        printf("Voulez-vous ajouter un nouveau fait ? Appuyer sur 1 pour continuer :  ");
        scanf("%d", &choix);
    }
    return bf;
}
bool non_doublon_bf(BF bf, char tab[]){
    if(bf==NULL){
        return true;
    }else{
        if (strcmp(bf->valeur,tab)==0){
            return false;
        }else{
            return non_doublon_bf(bf->suivant,tab);
        }
    }

}

BF supp_Bf(BF bf){   // à verifier si ça supprime bien tous les éléments

    if (bf->suivant==NULL){
        free(bf);
        return NULL;
    }else{
        bf = supp_Bf(bf->suivant);
        return(bf);
    }
}