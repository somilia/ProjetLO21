#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "allstructure.h"
#include "newBC.h"
void menuBC(BC bc, BF bf){
    int choix = 0;
    int conf = 0;
    while (choix != 6) {
        system("cls");
        printf("Que voulez vous faire?\n\n");
        printf("1) consulter l'ensemble de la base\n");
        printf("2) ajouter une regle\n");
        printf("3) consulter une regle\n");
        printf("4) suprimer une regle\n");
        printf("5) aajouter une base template\n");
        printf("6) retour menu principale");
        scanf("%d", &choix);

        switch (choix) {

            case 1 :
                consultertoutelaBC(bc);
                conitnuer();
                break;
            case 2:
                bc= ajoutregleBC(bc);

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

                conitnuer();

                break;

            case 5:
                bc=bctemplate(bc);
                break;
                case 6:
                    menuprincipale(bc, bf);

                     break;
            default:
                printf("entrer un choix valide");
                conitnuer();

                break;
        }
    }



}


BC ajoutregleBC(BC bc){
    char propo[20]={'\0'};
    Regle *regle=creerRegle(regle);
    int choix=1;
    while(choix==1) {
        printf("ajouter un Proposition de la presmisse:\n");
        scanf("%s", propo);             //verifier si propo est réinitialisé automatiquement sinon risque de bug
        regle->premier = ajouteEnQueRec(regle->premier, propo);
        printf("continuer la prémisse ? si oui appuyer sur 1\n");
        scanf("%d",&choix);
    }
    printf("entrer votre conslusion\n");
    scanf("%s",propo);
    regle=creerConclusion(regle,propo);
   bc= ajouteEnQueBc(bc,regle);
   return bc;
}

BC consultertoutelaBC(BC bc) {
    if (bc == NULL) {
        printf("\nfin\n");
    }else{


        afficherRegle(bc);
       consultertoutelaBC(bc->suivant);
    }
}

BC creerBC(){

    BC bc=malloc(sizeof(BC));
    Regle *regle = creerRegle();
    if (regle == NULL || regle->premier == NULL) {
        exit(EXIT_FAILURE);
    }

    bc=regle;


    return bc;
}

Regle* insertiondsr(int max ,char* tableau[],Regle *regle,char* conclusion){
    for(int i=0;i<max;i++){
        regle->premier=ajouteEnQueRec(regle->premier,tableau[i]);
    }
    regle=creerConclusion(regle, conclusion);
    return regle;
}


BC initBC(BC bc){ // Initialise la BC "Maladie" en ajoutant toutes les règles de symptomes=>maladie

    Regle *grippe = creerRegle();
    char* symptomeGrippe[4] = {"FIEVRE", "TOUX", "FATIGUE", "COURBATURE"};
    insertiondsr(4,symptomeGrippe,grippe,"grippe");
   /* for (int i=0; i<4; i++) {
        grippe->premier = ajouteEnQueRec(grippe->premier, symptomeGrippe[i]);
    }*/
  //  creerConclusion(grippe->premier, "grippe");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"FIEVRE", "TOUX", "MAL DE GORGE", "FATIGUE"};
    /*for (int i=0; i<4; i++) {
        angine->premier = ajouteEnQueRec(angine->premier, symptomeAngine[i]);
    }
    creerConclusion(angine->premier, "angine");*/
    insertiondsr(4,symptomeAngine,angine,"angine");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[4] = {"FIEVRE", "TOUX", "PERTE DE GOUT", "PERTE D'ODORAT"};
    /*for (int i=0; i<4; i++) {
        angine->premier = ajouteEnQueRec(covid19->premier, symptomeCovid19[i]);
    }
    creerConclusion(covid19->premier, "covid19");*/
    insertiondsr(4,symptomeCovid19,covid19,"covid19");

   // afficherRegle(grippe); // à enlever c'était pour test
  //  afficherRegle(angine); // à enlever c'était pour test

    bc = ajouteEnQueBc(bc , grippe);

    bc = ajouteEnQueBc(bc , angine);
    bc = ajouteEnQueBc(bc , covid19);
return bc;


}

/*BC ajouteEnQuebc(BC bc , Regle *regle){

    if (bc==NULL){
        bc=regle;
        bc->suivant=NULL;
        return bc;

    }

    bc->suivant=ajouteEnQuebc(restebc(bc),regle);


    return  bc;



}*/

BC ajouteEnQueBc(BC bc,  Regle *regle) { //Ajoute récursivement une proposition en queue


    if (bc != NULL ) {
        if(bc->premier->valeur[0]!=0){
            bc->suivant = ajouteEnQueBc(bc->suivant, regle);

        }
        else{
            bc=regle;

            return bc;
        }}
    else{
            bc=regle;

            return bc;
    }



    return bc;

}



/*BC restebc(BC bc){

    printf("tu es la1\n");

    if(bc.suivant->suivant==NULL) {
        printf("tu es la 2 ");

        bc.suivant=NULL;
        return bc;

    }else{


        printf("tu es la");

        bc.suivant = bc.suivant->suivant;
        return bc;
    }
}*/
Regle* renvoitetebc(BC bc){
    printf("renvoi de la tete , la valeur de la regle 1 est %c",bc->suivant->premier->valeur);
    return bc;
}


