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

#include "bc.h"





void consulterlisteRegle(BC bc,int compt){

    if(bc!=NULL){
        printf("%d : %s",compt,bc->conclusion->valeur);
        consulterlisteRegle(bc->suivant,compt++);
    }else{
        printf("fin");
    }

};