#include <ctype.h>

#include "allstructure.h"
#include "bc.h"
#include "regle.h"
#include "bf.h"
#include "menu.h"
#include "arbre.h"
#include "new_bc.h"

void menu_BC(BC bc, BF bf, char nom[]){
    
    int choix = 0;
    int conf = 0;
    while (choix != 6){
        system("cls");
        printf("Que voulez vous faire?\n\n");
        printf("1) Consulter l'ensemble de la base\n");
        printf("2) Ajouter une regle\n");
        printf("3) Consulter une regle\n");
        printf("4) Suprimer une regle\n");
        printf("5) Ajouter une base template\n");
        printf("6) Retour menu principale");
        scanf("%d", &choix);

        switch (choix){

            case 1 :
                system("cls");
                afficher(bc->arbre);
                afficher(bc->suivant->arbre);
                printf("%d %d %d", bc->nbpropo, bc->suivant->nbpropo, bc->suivant->suivant->nbpropo);
                consulter_toute_la_BC(bc);
                continuer();

                break;
            case 2:
                system("cls");
                bc = ajout_regle_BC(bc);
                continuer();

                break;
            case 3:
                system("cls");
                consulter_bc_regle(bc);
                continuer();

                break;
            case 4:
                system("cls");
                bc = supp_bc_regle(bc);
                continuer();

                break;

            case 5:
                system("cls");
                bc = bc_template(bc);

                break;
            case 6:
                system("cls");
                menu_principale(bc, bf, nom);

                break;
            default:
                printf("Entrez un choix valide");
                continuer();

                break;
        }
    }
}

BC supp_bc_regle(BC bc){
    
    char conclu[20];
    printf("Entrez la conclusion de la regle que vous voulez supprimer");
    scanf("%s", conclu);
    for(int i=0;i<strlen(conclu);i++){
        conclu[i] = tolower(conclu[i]);
    }
    bc = search_conclu_delete(bc, conclu);
    return bc;
}

BC search_conclu_delete(BC bc, char conclu[]){
    
    if(bc==NULL){
        printf("Cette conclusion n'est pas dans la base\n");
        return bc;
    }else{
        if(strcmp(bc->conclusion->valeur,conclu)==0){
            Regle *tempo=bc;
            bc = bc->suivant;
            supprimer_arbre(tempo->arbre);
            free(tempo->conclusion);
            free(tempo);
            printf("fait");
            continuer();
            return bc;
        }else{
            bc->suivant = search_conclu_delete(bc->suivant, conclu);
        }
    }
}

void consulter_bc_regle(BC bc){
    
    char conclu[20];
    printf("Entrez la conclusion de la regle que vous cherchez\n");
    scanf("%s",conclu);
    for(int i=0;i<strlen(conclu);i++){
        conclu[i] = tolower(conclu[i]);
    }
    search_conclu_show(bc, conclu);
}

BC search_conclu_show(BC bc, char conclu[]){
    
    if(bc==NULL || bc->conclusion==NULL){
        printf("Votre conclusion n'existe pas\n");
        return NULL;
    }else{
        if(strcmp(bc->conclusion->valeur, conclu)==0){
            printf("Voici la regle:\n");
            afficherRegle(bc);
            return NULL;
        }else{
            bc->suivant = search_conclu_show(bc->suivant, conclu);
            return bc;
        }
    }
}

BC ajout_regle_BC(BC bc){
    
    char propo[20] = {'\0'};

    int choix = 1;
    printf("Entrez votre conclusion\n");
    scanf("%s", propo);
    if(verification_conclusion_unique(bc, propo)==0){
        return bc;

    }else{
        Regle *regle = creerRegle();
        regle = creerConclusion(regle, propo);
    while(choix==1){
        printf("Ajouter un Proposition de la prémisse:\n");
        scanf("%s", propo);             // verifier si propo est réinitialisé automatiquement sinon risque de bug
        regle = ajouteEnQueueRegle(regle, propo);

        regle->arbre = creer_arbre_complet(regle->arbre, propo); //!!!!!!!!!!!!!!!!!!!
        printf("Continuer la prémisse ? Si oui appuyer sur 1 :  \n");
        scanf("%d", &choix);
    }
    bc = ajoute_en_queue_BC(bc, regle);
    return bc;
    }
}

int verification_conclusion_unique(BC bc, char conclusion[]){

    if(bc==NULL || bc->premier->valeur[0]==' '){
        return 1;
    }else{
        if(strcmp(bc->conclusion->valeur, conclusion)==0){
            printf("Votre conclusion existe déja\n");
            return 0;
        }else{
           return verification_conclusion_unique(bc->suivant, conclusion);
        }
    }
}

void consulter_toute_la_BC(BC bc){
    
    if (bc==NULL ){
        printf("\nfin\n");
    }else {
        if (bc->premier->valeur[0]==' '){
            printf("\nfin\n");
        } else {
            afficherRegle(bc);
            consulter_toute_la_BC(bc->suivant);
        }
    }
}

BC creer_BC(){

    BC bc = malloc(sizeof(BC));
    Regle *regle = creerRegle();
    if (regle==NULL || regle->premier==NULL){
        exit(EXIT_FAILURE);
    }
    bc = regle;
    return bc;
}

Regle* insertiondsr(int max, char* tableau[], Regle *regle, char* conclusion){
    
    for(int i=0;i<max;i++){
        regle->arbre = creer_arbre_complet(regle->arbre, tableau[i]);
        regle = ajouteEnQueueRegle(regle, tableau[i]); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    regle=creerConclusion(regle, conclusion);
    regle->suivant = NULL;
    return regle;
}

BC ajoute_en_queue_BC(BC bc, Regle *regle){   // Ajoute récursivement une proposition en queue
    
    if(bc==NULL){
        bc = regle;
        return bc;
    }else{
        if(bc->premier->valeur[0]==' '){
            bc = regle;
            return bc;
        }else{
            bc->suivant = ajoute_en_queue_BC(bc->suivant, regle);
            return bc;
        }
    }
}

/*BC restebc(BC bc){

    printf("tu es la1\n");

    if(bc.suivant->suivant==NULL){
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
    printf("Renvoi de la tete, la valeur de la regle 1 est %c",bc->suivant->premier->valeur);
    return bc;
}


