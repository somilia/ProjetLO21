//
// Created by denis on 14/12/2020.
//
#include "allstructure.h"
#include "fichier.h"
#include "bc.h"
#include "arbre.h"
#include <stdio.h>
#include <string.h>
#include "regle.h"
void ajout_regle_fichier(Regle *regle, char nom[]) {




    FILE *fichier = NULL;
    char chaineremplacer[100] = {0};
    strcat(chaineremplacer, nom);
    strcat(chaineremplacer, ".txt");
    fichier = fopen(chaineremplacer, "w+");
    fseek(fichier, 0, SEEK_SET);

    if (fichier != NULL) {
        while(regle!=NULL) {


            fprintf(fichier, "%s ", regle->conclusion->valeur);
            Proposition *continu = regle->premier;
            while (continu != NULL) {
                fprintf(fichier, "%s ", continu->valeur);
                continu = continu->suivant;
            }
            fprintf(fichier, ".\n");
            regle=regle->suivant;
        }
        fseek(fichier, -2,SEEK_CUR);

        fprintf(fichier, ";");

    }

    fclose(fichier);
}










/*BC initialisation_creation_bc(BC bc, char nom[]){
    FILE *fichier = NULL;
    char chaineremplacer[100] = {0};
    strcat(chaineremplacer, nom);
    strcat(chaineremplacer, ".txt");
    fichier = fopen(chaineremplacer, "r");
    fseek(fichier, 0, SEEK_SET);

    Regle *regle=malloc(sizeof(Regle));


    if(fichier!=NULL) {
        int i=0;
        int error=0;
        char mot[100]={0};
while( fgetc(fichier)!=EOF && error==0) {
    fseek(fichier, -1,SEEK_CUR);
    i=0;
    regle = creerRegle();
    while (fgetc(fichier) != '\n') {
        fseek(fichier, -1,SEEK_CUR);
    i=0;
if(fgetc(fichier)==EOF){
    error=1;
}
        if (regle->conclusion==NULL) {
            while (mot[i] != '\0') {
                mot[i] = '\0';
                i++;
            }
            i=0;
            while (fgetc(fichier)!= 32) {
                fseek(fichier, -1,SEEK_CUR);
               mot[i] = fgetc(fichier);
                i++;
            }
            regle=creerConclusion(regle,mot);
        }
        i=0;
        while (mot[i] != '\0') {
            mot[i] = '\0';
            i++;
        }
        i=0;
        while (fgetc(fichier) != ' ') {
            fseek(fichier, -1,SEEK_CUR);
            mot[i] = fgetc(fichier);
            i++;
        }

        regle = ajouteEnQueRegle(regle, mot);


    }


    bc=ajout_regle_bc_fichier(bc,*regle);
printf("%s",bc->premier->valeur);
    regle=supp_regle(regle);
}

fclose(fichier);
    }


    return bc;
}*/
BC initialisation_creation_bc(BC bc, char nom[]){
    FILE *fichier = NULL;
    char chaineremplacer[100] = {0};
    strcat(chaineremplacer, nom);
    strcat(chaineremplacer, ".txt");
    fichier = fopen(chaineremplacer, "r");
    fseek(fichier, 0, SEEK_SET);

    Regle *regle=malloc(sizeof(Regle));
int fin=0;

    if(fichier!=NULL) {
        int i=0;
        int error=0;
        char mot[100]={0};
        while( fin==0 ) {

            i=0;
            regle = creerRegle();
            while (mot[0] != '.' ) {
                i=0;
                while (mot[i] != '\0') {
                    mot[i] = '\0';
                    i++;
                }
              //  fseek(fichier, -1,SEEK_CUR);
                i=0;

                if (regle->conclusion==NULL) {
                    fscanf(fichier, "%s",mot);
                    regle=creerConclusion(regle,mot);
                }
                i=0;
                while (mot[i] != '\0') {
                    mot[i] = '\0';
                    i++;
                }
                i=0;
                fscanf(fichier, "%s",mot);

                if(mot[0]!='.' ) {
                    regle->arbre= creerarbre_complet(regle->arbre,mot);
                    regle = ajouteEnQueRegle(regle, mot);
                }


            }
            if(mot[1]==';'){
                fin =1;
            }else{
                mot[0]='\0';
            }

            bc=ajout_regle_bc_fichier(bc,regle);
            printf("%s",bc->premier->valeur);
            regle=NULL;
        }

        fclose(fichier);
        free(regle);
    }


    return bc;
}


BC ajout_regle_bc_fichier(BC bc, Regle *regle){


    Regle* pointeur = regle;
    bc=ajouteEnQueBc(bc,pointeur);
    return bc;
}
Regle *supp_regle(Regle *regle){



        if(regle->conclusion!=NULL){
            free(regle->conclusion);
        }
        regle->premier=supp_regle_premier(regle->premier->suivant);

    return regle;
}

Proposition* supp_regle_premier(Proposition* propo){
    if(propo!=NULL){
        propo=supp_regle_premier(propo->suivant);
        free(propo);
    }else{
        return NULL;
    }
}