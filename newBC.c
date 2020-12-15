//
// Created by denis on 03/12/2020.
//

#include "newBC.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "consulter.h"
#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "bc.h"
#include "allstructure.h"
BC bctemplate(BC bc){
    int choix=0;
    while(choix<1 || choix >5){
    printf("voici les bc disponible");
    printf("1) maladie\n");
    printf("2) foot champion du monde\n");
    printf("3)");
    printf("4)");
    printf("5)");
    printf("laquelle voulez vous?");
    scanf("%d",&choix);}
    switch (choix){

        case 1:
            bc=BCmaladie(bc);
            break;
        case 2:
            bc=BCfootchampiondumonde(bc);
            break;

    }
    return bc;
}





BC BCmaladie(BC bc){        //en minuscules et un seul mot !
    Regle *grippe = creerRegle();
    char* symptomeGrippe[4] = {"fievre", "toux", "fatigue", "courbature"};
    insertiondsr(4,symptomeGrippe,grippe,"grippe");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"fievre", "toux", "mal_de_gorge", "fatigue"};

    insertiondsr(4,symptomeAngine,angine,"angine");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[4] = {"fievre", "toux", "perte_de_gout", "perte_odorat"};

    insertiondsr(4,symptomeCovid19,covid19,"covid19");


    bc = ajouteEnQueBc(bc , grippe);

    bc = ajouteEnQueBc(bc , angine);
    bc = ajouteEnQueBc(bc , covid19);

    return bc;
}
BC BCfootchampiondumonde(BC bc){        //en minuscules et un seul mot !
    Regle *grippe = creerRegle();
    char* symptomeGrippe[6] = {"dugarry", "trezeguet", "zidane", "deschamps","desailly","blanc"};
    insertiondsr(4,symptomeGrippe,grippe,"France_1998");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"griezmann", "lloris", "pogba", "giroud"};

    insertiondsr(4,symptomeAngine,angine,"France_2018");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[5] = {"puyol", "xavi", "iniesta", "villa","torres"};

    insertiondsr(4,symptomeCovid19,covid19,"Espagne_2010");


    bc = ajouteEnQueBc(bc , grippe);

    bc = ajouteEnQueBc(bc , angine);
    bc = ajouteEnQueBc(bc , covid19);

    return bc;
}