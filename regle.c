#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "regle.h"


Regle creerRegle() {
    Regle regle = malloc(sizeof(Regle));
    Proposition *proposition = malloc(sizeof(Proposition));

    if (regle == NULL || proposition == NULL) {
        exit(EXIT_FAILURE);
    }

    proposition->valeur = '_';
    proposition->suivant = NULL;
    regle = proposition;

    return regle;
}
// Cette fonction n'a pas vrm de sens pour l'instant
/*Proposition *creerConclusion(Regle *regle, char vConclu) { // Créer la conclusion d'une règle
    Proposition *conclusion = malloc(sizeof(Proposition));
    conclusion->valeur = vConclu;
    conclusion->suivant = NULL;

    ajouteEnQueRec(regle, conclusion->valeur);

    return conclusion;
}*/

Regle ajouteEnTete(Regle regle, char nvProp) {

    Proposition *nouveau = malloc(sizeof(*nouveau));
    nouveau->valeur = nvProp;
    nouveau->suivant=regle;
    return regle;
}

Proposition creerProposition(char nvProp){
    Proposition *nouveau = malloc(sizeof(*nouveau));
    nouveau->valeur = nvProp;
    nouveau->suivant = NULL;
    return *nouveau;

}

Regle ajouteEnQueRec(Regle regle, char nvProp) { //Ajoute récursivement une proposition en queue


    if (regle == NULL) {
        Proposition *nouveau = malloc(sizeof(*nouveau));
        nouveau->valeur = nvProp;
        nouveau->suivant = NULL;

        return nouveau;
    }else{

        regle->suivant=ajouteEnQueRec(regle->suivant, nvProp);
        return regle;
    }


}

Regle reste(Regle regle){
    if(regle==NULL){

        return regle;
    }else{
        Proposition *nouveau = regle;
        regle=regle->suivant;
        free(nouveau);
        return regle;


    }
}

Regle suppressionTeteRec(Regle regle) { // Supprime récursivement la tête


    if(regle!=NULL)
    {
        /*Regle *tmp;
        tmp=regle->suivant;
        free (regle);
        return tmp;*/

        Proposition *pSupp;
        pSupp = regle;
        regle = regle->suivant;
        free (pSupp);
        return regle;
    }else {
        return NULL;
    }
}

Regle suppressionRec(Regle regle, char vSupp) { // Supprime récursivement une proposition de la prémisse

    if(regle==NULL) return NULL;

    if (!rechercheRec(regle, vSupp)) { // On vérifie que l'élément est présent dans la liste
        exit(EXIT_FAILURE);
    }

    if(regle->suivant->valeur==vSupp) {
        Proposition *pSupp = regle->suivant;
        regle->suivant = regle->suivant->suivant;
        free(pSupp);

        return regle;
    }

    regle = regle->suivant;
    return suppressionRec(regle, vSupp);

}

void afficherRegle(Regle regle)
{
    /*if (regle == NULL)
    {
        exit(EXIT_FAILURE);
    }*/

    Proposition *actuel = regle;

    while (actuel != NULL)
    {
        printf("%c -> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// wtf elle marche cette fonction, elle renvoie 0 pour la liste test
bool rechercheRec(Proposition *regle, char vRecherche) { // Test si une proposition appartient à la règle

    if(regle==NULL) return false;
    if(regle->valeur==vRecherche) {
        return true;
    }
    return rechercheRec(regle->suivant,vRecherche);
}

bool isEmpty(Regle regle) { // Test si la prémisse est vide
    if (regle == NULL) return true;
    else return false;
}
char valeurTete(Regle regle) { // Proposition en tête de la prémisse
    return regle->valeur;
}
char valeurQueue(Regle regle) { // Conclusion de la prémisse
    if(regle==NULL) exit(EXIT_FAILURE) ;


    if(regle->suivant==NULL) {

        return regle->valeur;
    }
    regle = regle->suivant;
    return valeurQueue(regle);
}

/**
int count_recur(Regle regle) {
    if (isEmpty(1)) {
        return 0;
    } else {
        return 1+count_recur(rest(1));
    }
}**/
/**
int contains_r(Regle regle, int v) {
    if (isEmpty(1)) {
        return 0;
    } else {
        if (valeurTete(1) == v) {
            return 1;
        }
        ...
    }
}**/


/**
Proposition *insertion(Proposition *regle, char nvProp)   // Fonction itérative, ne marche pas correctement
{

    // Création du nouvel élément
    Proposition *nouveau = malloc(sizeof(*nouveau));
    if (regle == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = nvProp;
    nouveau->suivant = NULL;

    if (regle->valeur = '_') { // liste vide
        // Insertion de l'élément au début de la liste
        nouveau->suivant = NULL;
        regle = nouveau;
    }
    else {
        Proposition *tmp = regle;
        while (regle->suivant != NULL) {
            regle = regle->suivant;
        }
        regle->suivant = nouveau;
        return tmp;
    }
}**/
/**
void suppression(Regle *regle, char valeurSupp)
{
    Proposition *PropSupp;
    PropSupp->valeur = valeurSupp;
    if (regle == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (regle->premier != NULL)
    {
        if (regle->premier = PropSupp) {
            regle->premier = regle->premier->suivant;
            free(PropSupp);
        }
        else {
            Proposition *tmp = regle->premier;
            while (tmp != NULL) {
                if (tmp->suivant->valeur == PropSupp->valeur) {
                    tmp->suivant = tmp->suivant->suivant;
                    free(PropSupp);
                }
                tmp = tmp->suivant;
            }
        }
    }
}**/
/**
Proposition *recherche_rec(Proposition *regle, char vRecherche) {

    if (regle == NULL) return NULL;
    if (regle->valeur == vRecherche) {
        Proposition *pRecherche = malloc(sizeof(*pRecherche));
        pRecherche->valeur = vRecherche;
        return pRecherche;
    }
    return recherche_rec(regle->suivant, vRecherche);
}**/