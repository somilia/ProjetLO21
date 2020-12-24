#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "allstructure.h"
#include "regle.h"
#include "bc.h"
#include "bf.h"
#include "arbre.h"
#include "menu.h"
#include "consulter.h"
#include "testbase.h"
#include "fichier.h"
#include "new_comparing.h"

void initialisation(){

    BC bc= creer_BC();
    BF bf=creer_Bf();
    char nom[5]={0};

    printf("Entrez votre nom :  ");
    scanf("%s", nom);
    menu_principale(bc, bf, nom);
}

void menu_principale(BC bc, BF bf, char nom[]){

    int choix=0;

    while(choix!=7){
        system("cls");
        printf("*************Bienvenue****************");
        printf("\n\n\nQue voulez-vous faire : \n");
        printf("1) Menu base de connaissance\n");
        printf("2) Menu base de faits\n");
        printf("3) Lire une regle\n");
        printf("4) Menu des sauvegardes\n");
        printf("5) Moteur d'inférence\n");
        printf("6) Simple recherche\n");
        printf("7) Quitter\n");
        scanf("%d", &choix);

    switch (choix){
        case 1 :
            menu_BC(bc, bf, nom);

            break;
        case 2:
            menu_Bf(bc, bf, nom);

            break;
        case 3:
            system("cls");
            consulter_bc_regle(bc);
            continuer();

            break;
        case 4:
           // ajout_regle_fichier(bc,"evan");
            menu_sauvegarde(bc, bf, nom);

            break;
        case 5:
            system("cls");
            menu_comparaison_automatique(bc, bf);
            continuer();

            break;
        case 6:
            system("cls");
            menu_comparaison(bc, bf);
            continuer();

            break;
        case 7:
            exit(1);
        }
    }
}

void menu_sauvegarde(BC bc, BF bf, char nom[]){

    int choix=0;
    while(choix != 1 && choix !=2 && choix!=3){
    printf("Que voulez-vous faire ?\n");
    printf("1) Récupération de donnée");
    printf("2) Déposer les données");
    printf("3) Retour");
    scanf("%d",&choix);

    switch(choix){
        case 1 : bc= initialisation_creation_bc(bc, nom);
            break;
        case 2:
            ajout_regle_fichier(bc, nom);
            break;
        case 3:
            menu_principale(bc, bf, nom);
            break;
        }
    }
    continuer();
    menu_principale(bc, bf, nom);
}