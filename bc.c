#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "menu.h"
#include "arbre.h"

#include "allstructure.h"
#include "newBC.h"
#include <ctype.h>
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
        printf("5) ajouter une base template\n");
        printf("6) retour menu principale");
        scanf("%d", &choix);

        switch (choix) {

            case 1 :
                system("cls");

                consultertoutelaBC(bc);
                conitnuer();
                break;
            case 2:
                system("cls");

                bc= ajoutregleBC(bc);

                conitnuer();

                break;
            case 3:
                system("cls");

                consulter_bc_regle(bc);

                conitnuer();

                break;
            case 4:
                system("cls");

                bc=supp_bc_regle(bc);
                conitnuer();

                break;

            case 5:
                system("cls");

                    bc=bctemplate(bc);
                break;
                case 6:
                    system("cls");

                menuprincipale(bc, bf);

                     break;
            default:
                printf("entrer un choix valide");
                conitnuer();

                break;
        }
    }



}

BC supp_bc_regle(BC bc){
    char conclu[20];
    printf("entrer la conclusion de la regle que vous voulez supprimer");
    scanf("%s",conclu);
    for(int i=0;i<strlen(conclu);i++){
        conclu[i]=tolower(conclu[i]);
    }
    bc=searchconclu_delete(bc,conclu);
    return bc;
}

BC searchconclu_delete(BC bc,char conclu[]){
    if(bc==NULL){
        printf("Cette conclusion n'est pas dans la base\n");

        return bc;
    }else{
        if(strcmp(bc->conclusion->valeur,conclu)==0){
            Regle *tempo=bc;
            bc=bc->suivant;
            suprimer_arbre(tempo->arbre);
            free(tempo->conclusion);
            free(tempo);
            printf("fait");
            conitnuer();
            return bc;
        }else{
            bc->suivant=searchconclu_delete(bc->suivant,conclu);
        }
    }
}



void consulter_bc_regle(BC bc){
    char conclu[20];
    printf("entrer la conclusion de la regle que vous chercher\n");
    scanf("%s",conclu);
    for(int i=0;i<strlen(conclu);i++){
        conclu[i]=tolower(conclu[i]);
    }
    searchconclu_show(bc,conclu);
}
BC searchconclu_show(BC bc,char conclu[]){
    if(bc==NULL || bc->conclusion==NULL){
        printf("votre conclusion n'existe pas \n");
    return NULL;
    }else{
        if(strcmp(bc->conclusion->valeur,conclu)==0){
            printf("voici la regle:\n");
            afficherRegle(bc);
            return NULL;
        }else{
            bc->suivant=searchconclu_show(bc->suivant,conclu);
            return bc;
        }
    }
}

BC ajoutregleBC(BC bc){
    char propo[20]={'\0'};

    int choix=1;
    printf("entrer votre conslusion\n");
    scanf("%s",propo);
    if(verification_conclusion_unique(bc,propo)==0){
        return bc;

    }else {
        Regle *regle=creerRegle();
        regle = creerConclusion(regle, propo);
    while(choix==1) {
        printf("ajouter un Proposition de la presmisse:\n");
        scanf("%s", propo);             //verifier si propo est réinitialisé automatiquement sinon risque de bug
        regle = ajouteEnQueRegle(regle, propo);

         regle->arbre=creerarbre_complet(regle->arbre, propo); //!!!!!!!!!!!!!!!!!!!
            printf("continuer la prémisse ? si oui appuyer sur 1\n");
        scanf("%d",&choix);
    }


        bc = ajouteEnQueBc(bc, regle);
        return bc;

    }}
int verification_conclusion_unique(BC bc,char conclusion[]){

    if(bc==NULL|| bc->premier->valeur[0]=='a'){
        return 1;
    }else{
        if(strcmp(bc->conclusion->valeur,conclusion)==0){
            printf("votre conclusion existe déja");
            return 0;
        }else{
           return verification_conclusion_unique(bc->suivant,conclusion);
        }
    }
}
void consultertoutelaBC(BC bc) {
    if (bc == NULL ) {
        printf("\nfin\n");
    }else {
        if (bc->premier->valeur[0] == 'a') {
            printf("\nfin\n");
        } else {


            afficherRegle(bc);
            consultertoutelaBC(bc->suivant);
        }
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
        regle->arbre=creerarbre_complet(regle->arbre, tableau[i]);
        regle=ajouteEnQueRegle(regle,tableau[i]); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    regle=creerConclusion(regle, conclusion);
    regle->suivant=NULL;
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
if(bc==NULL){

    bc=regle;

    return bc;
}else{
    if(bc->premier->valeur[0]=='a'){
        bc=regle;
        return bc;
    }else{
        bc->suivant = ajouteEnQueBc(bc->suivant, regle);
        return bc;
    }
}






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


