//
// Created by denis on 02/12/2020.
//
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "consulter.h"
#include <ctype.h>
#include "bc.h"

void nomreglerechercher(char nomregle[]){//permet à l'utilisateur d'entrer le nom de la regle qu'il cherche

    printf("entrez le nom de la regle que vous voulez voir");
    scanf("%s",nomregle);
    for(int i=0;i<strlen(nomregle);i++){
        nomregle[i]=tolower(nomregle[i]);
    }
};

void lirereglechoisis(BC bc){
    char nomregle[20];
    nomreglerechercher(nomregle);
    consulterreglechoisi(nomregle,bc);
}


void consulterlisteRegle(BC bc,int compt){

    if(bc!=NULL){
        printf("\n%d : %s",compt,bc->conclusion->valeur);
        consulterlisteRegle(bc->suivant,compt+1);
    }else{
        printf("\nfin\n");
    }

};


void consulterreglechoisi(char nom[], BC bc){   //passer la chaine de caractere en minuscules avant !
    if(strcmp(bc->conclusion->valeur,nom)==0){
        afficherRegle(bc);
    }else{
        consulterreglechoisi(nom,bc->suivant);
    }
}