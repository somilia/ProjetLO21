//
// Created by denis on 06/12/2020.
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
#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "allstructure.h"
#include "testbase.h"
#include "arbre.h"

BC test_bd_bf(BC bc, BF bf){
    if(bc==NULL){
        printf("inconnu");
        return NULL;
    }else{

    }
}

int corespondance(BC bc, BF bf){
    arbreb arbrebc=creerarbre();
    arbreb arbrebf=creerarbre();

    arbrebc=inserer_regle_arbre(arbrebc,bc->premier);
    arbrebf=inserer_regle_arbre(arbrebf,bf);

}