#include "bc.h"
#include "regle.h"


BC creerBC(){

    BC bc=malloc(sizeof(BC));
    Regle *regle = creerRegle();
    if (regle == NULL || regle->premier == NULL) {
        exit(EXIT_FAILURE);
    }

    bc=regle;


    return bc;
}

void initBC(BC bc){ // Initialise la BC "Maladie" en ajoutant toutes les règles de symptomes=>maladie

    Regle *grippe = creerRegle();
    char* symptomeGrippe[4] = {"FIEVRE", "TOUX", "FATIGUE", "COURBATURE"};
    for (int i=0; i<4; i++) {
        grippe->premier = ajouteEnQueRec(grippe->premier, symptomeGrippe[i]);
    }
    creerConclusion(grippe->premier, "grippe");

    Regle *angine = creerRegle();
    char* symptomeAngine[4] = {"FIEVRE", "TOUX", "MAL DE GORGE", "FATIGUE"};
    for (int i=0; i<4; i++) {
        angine->premier = ajouteEnQueRec(angine->premier, symptomeAngine[i]);
    }
    creerConclusion(angine->premier, "angine");

    Regle *covid19 = creerRegle();
    char* symptomeCovid19[4] = {"FIEVRE", "TOUX", "PERTE DE GOUT", "PERTE D'ODORAT"};
    for (int i=0; i<4; i++) {
        angine->premier = ajouteEnQueRec(covid19->premier, symptomeCovid19[i]);
    }
    creerConclusion(covid19->premier, "covid19");

    afficherRegle(grippe); // à enlever c'était pour test
    afficherRegle(angine); // à enlever c'était pour test


    bc = ajouteEnQueBc(bc , grippe->premier);
    bc = ajouteEnQueBc(bc , angine->premier);
    bc = ajouteEnQueBc(bc , covid19->premier);



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

Regle * ajouteEnQueBc(Regle* bc,  Proposition *regle) { //Ajoute récursivement une proposition en queue


    if (bc   == NULL || bc->premier->valeur=="\0") {
        printf("bc est null\n");
        Regle *nouveau = malloc(sizeof(*nouveau));
        nouveau->premier = regle;
        nouveau->suivant = NULL;

        return nouveau;
    }
    printf("bc est passsssssss null\n");

    bc->suivant = ajouteEnQueBc(bc->suivant, regle);

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


