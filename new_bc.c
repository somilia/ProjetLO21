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
#include "new_bc.h"

BC bc_template(BC bc){
    
    int choix=0;
    while(choix<1 || choix >5){
        printf("Voici les bc disponible");
        printf("1) maladie\n");
        printf("2) foot champion du monde\n");
        printf("3)");
        printf("4)");
        printf("5)");
        printf("Laquelle voulez-vous?");
        scanf("%d",&choix);
    }
    switch (choix){
        case 1:
            bc= BC_maladie(bc);
            break;
        case 2:
            bc= BC_footchampiondumonde(bc);
            break;
    }
    return bc;
}

BC BC_maladie(BC bc){        //en minuscules et un seul mot !
    
    Regle *grippe = creerRegle();
    char* symptomeGrippe[4] = {"fievre", "toux", "fatigue", "courbature"};
    insertiondsr(4,symptomeGrippe,grippe,"grippe");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"fievre", "toux", "mal_de_gorge", "fatigue"};
    insertiondsr(4,symptomeAngine,angine,"angine");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[4] = {"fievre", "toux", "perte_de_gout", "perte_odorat"};
    insertiondsr(4,symptomeCovid19,covid19,"covid19");
    
    bc = ajoute_en_queue_BC(bc, grippe);
    bc = ajoute_en_queue_BC(bc, angine);
    bc = ajoute_en_queue_BC(bc, covid19);

    return bc;
}

BC BC_footchampiondumonde(BC bc){        //en minuscules et un seul mot !
    
    Regle *grippe = creerRegle();
    char* symptomeGrippe[6] = {"dugarry", "trezeguet", "zidane", "deschamps", "desailly", "blanc"};
    insertiondsr(4,symptomeGrippe,grippe,"France_1998");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"griezmann", "lloris", "pogba", "giroud"};
    insertiondsr(4,symptomeAngine,angine,"France_2018");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[5] = {"puyol", "xavi", "iniesta", "villa", "torres"};
    insertiondsr(4,symptomeCovid19,covid19,"Espagne_2010");

    bc = ajoute_en_queue_BC(bc, grippe);
    bc = ajoute_en_queue_BC(bc, angine);
    bc = ajoute_en_queue_BC(bc, covid19);

    return bc;
}