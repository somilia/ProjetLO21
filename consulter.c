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

void nom_regle_rechercher(char nomregle[]){  // permet à l'utilisateur d'entrer le nom de la règle qu'il cherche

    printf("Entrez le nom de la regle que vous voulez voir :  ");
    scanf("%s", nomregle);
    for(int i=0;i<strlen(nomregle);i++){
        nomregle[i] = tolower(nomregle[i]);
    }
}

void lire_regle_choisi(BC bc){

    char nomregle[20];
    nom_regle_rechercher(nomregle);
    consulter_regle_choisi(nomregle, bc);
}

void consulter_liste_regle(BC bc, int compt){

    if(bc!=NULL){
        printf("\n%d : %s",compt,bc->conclusion->valeur);
        consulter_liste_regle(bc->suivant, compt + 1);
    }else{
        printf("\nfin\n");
    }
}

void consulter_regle_choisi(char nom[], BC bc){   // passer la chaîne de caractère en minuscules avant !

    if(strcmp(bc->conclusion->valeur, nom)==0){
        afficherRegle(bc);
    }else{
        consulter_regle_choisi(nom, bc->suivant);
    }
}