#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regle.h"
#include "bc.h"
#include "regle.h"
#include "BF.h"
#include "allstructure.h"
#include "menu.h"
#include "arbre.h"

Regle *creerRegle() {
    Regle *regle = malloc(sizeof(Regle));
    Proposition *proposition = malloc(sizeof(Proposition));

    if (regle == NULL || proposition == NULL) {
        exit(EXIT_FAILURE);
    }

    proposition->valeur[0]=' ';
 //   proposition->valeur = "\0";
    proposition->suivant = NULL;
    regle->premier = proposition;
    regle->conclusion=NULL;
    regle->suivant=NULL;
    regle->arbre=NULL;
    regle->arbre=creerarbre();
    regle->nbpropo=0;
    return regle;
}

Regle *creerConclusion(Regle *regle, char* vConclu) { // Créer la conclusion d'une règle
    Proposition *conclusion = malloc(sizeof(Proposition));
    strcpy(conclusion->valeur, vConclu);

    conclusion->suivant = NULL;
    regle->conclusion=conclusion;
    return regle;
}

Proposition *ajouteEnTete(Regle *regle, char* nvProp) {

    Proposition *nouveau = malloc(sizeof(*nouveau));
   // nouveau->valeur = nvProp;
    strcpy(nouveau->valeur, nvProp);
    nouveau->suivant=regle->premier;
    return nouveau;
}
Regle *ajouteEnQueRegle(Regle* regle, char prop[]){
    regle->nbpropo++;
    regle->premier=ajouteEnQueRec(regle->premier,prop);
    return regle;
}
Proposition *ajouteEnQueRec(Proposition *regle, char nvProp[]) { //Ajoute récursivement une proposition en queue


    if (regle == NULL || regle->valeur[0]==' ') {

        Proposition *nouveau = malloc(sizeof(*nouveau));
       // nouveau->valeur = nvProp;
        strcpy(nouveau->valeur, nvProp);
        nouveau->suivant = NULL;

        return nouveau;
    }
    regle->suivant = ajouteEnQueRec(regle->suivant, nvProp);
    return regle;

}

Regle *suppressionTeteRec(Regle *regle) { // Supprime récursivement la tête


    if(regle!=NULL)
    {
        /*Regle *tmp;
        tmp=regle->suivant;
        free (regle);
        return tmp;*/

        Proposition *pSupp;
        pSupp = regle->premier;
        regle->premier = regle->premier->suivant;
        free (pSupp);
        return regle;
    }else {
        return NULL;
    }
}
// A MODIFIER, elle ne fonctionne pas avec le char*
Regle *suppressionRec(Regle *regle, char *vSupp) { // Supprime récursivement une proposition de la prémisse

    if(regle==NULL) return NULL;

    if (!rechercheRec(regle->premier, vSupp)) { // On vérifie que l'élément est présent dans la liste
        exit(EXIT_FAILURE);
    }

    if(regle->premier->suivant->valeur==vSupp) {
        Proposition *pSupp = regle->premier->suivant;
        regle->premier->suivant = regle->premier->suivant->suivant;
        free(pSupp);

        return regle;
    }

    regle->premier = regle->premier->suivant;
    return suppressionRec(regle, vSupp);

}

void afficherRegle(Regle *regle)
{
    if (regle == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(regle->premier==NULL){       //euuuu a vérifier ca

    }else{
    if ( regle->conclusion==NULL){
        printf("cette regle n'a pas de conclusion");
    }else
        {
    Proposition *actuel = regle->premier;
    printf("voici la premisse : \n");
    while (actuel != NULL)
    {
        printf("%s -> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("\n conclusion : %s \n\n",regle->conclusion->valeur);
    }
    }
}

// wtf elle marche cette fonction, elle renvoie 0 pour la liste test
bool rechercheRec(Proposition *regle, char *vRecherche) { // Test si une proposition appartient à la règle

    if(regle==NULL) return false;
    if(regle->valeur==vRecherche) {
        return true;
    }
    return rechercheRec(regle->suivant,vRecherche);
}

bool isEmpty(Regle *regle) { // Test si la prémisse est vide
    if (regle->premier == NULL) return true;
    else return false;
}
char* valeurTete(Regle *regle) { // Proposition en tête de la prémisse
    return regle->premier->valeur;
}
char* valeurQueue(Regle *regle) { // Conclusion de la prémisse
    if(regle==NULL) exit(EXIT_FAILURE) ;


    if(regle->premier->suivant==NULL) {

        return regle->premier->valeur;
    }
    regle->premier = regle->premier->suivant;
    return valeurQueue(regle);
}
