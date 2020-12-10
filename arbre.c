//
// Created by denis on 06/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arbre.h"



arbreb enraciner(arbreb a1,arbreb a2,int e){
    arbreb temp;
    temp=(noeud*)malloc(sizeof(noeud));
    temp->propo[0]='a';
    temp->fd=a1;
    temp->fg=a2;
    return temp;
}
void suprimer_arbre(arbreb arbre){

    if(arbre==NULL){

    }else{
        suprimer_arbre(arbre->fg);
        suprimer_arbre(arbre->fd);
        free(arbre);
    }


}
noeud *creerFeuille(char propo[]){
    noeud *new=malloc(sizeof(noeud));
    new->fd=NULL;
    new->fg=NULL;
    strcpy(new->propo,propo);
    return new;
}
arbreb creerarbre() {
    noeud *new = malloc(sizeof(noeud));
    new->fd = NULL;
    new->fg = NULL;
    new->propo[0] = 'a';
    arbreb newarbre = new;
    return newarbre;
}

void afficher(arbreb arbre){
    if(arbre==NULL){

}else{
    printf("%s",arbre->propo);
        afficher(arbre->fg);
        afficher(arbre->fd);

}

    
};

arbreb creerarbre_complet(arbreb arbre, char propo[]){

    if(arbre==NULL){
        return creerFeuille(propo);

    }else{
        if(arbre->propo[0]=='a'){
            return creerFeuille(propo);

        }else{
        if(propo[0]<arbre->propo[0]){
            arbre->fg=creerarbre_complet(arbre->fg,propo);
            return arbre;
        }else{
            arbre->fd=creerarbre_complet(arbre->fd,propo);
            return arbre;
        }
        }
    }

}


Regle* inserer_regle_arbre( BC bc,BF bf){
    if(bc==NULL){
        return NULL;
    }

     if (corespondace(bc->arbre, bf)==1){
         return bc;
     }else{
         bc=bc->suivant;
         inserer_regle_arbre(bc,bf);
     }
}

int corespondace(arbreb arbre,BF bf) {
    int solution;
    if (arbre == NULL) {
        return 0;
    } else {
        if (strcmp(bf->valeur, arbre->propo) == 0) {
            return 1;

        } else {
            if (bf->valeur[0] > arbre->propo[0]) {
                solution = corespondace(arbre->fd, bf);
                return solution;
            } else {
                if (bf->valeur[0] < arbre->propo[0]) {
                    solution = corespondace(arbre->fg, bf);
                    return solution;
                } else {
                    int i = 1;//on commence i à un car on a deja tester le premiere element
                    int max1 = strlen(
                            bf->valeur);          // on utilise la fonction strlen ici pour la premire fois car comme c'est une fonction qui va réalisé un certain nombre d'action on attend avant dde l'utiliser pour la premiere fois la reponse du premier teste pour savoir si c'est nécéssaire
                    int max2 = strlen(arbre->propo);
                    while (i < max1 || i < max2 || bf->valeur[i] != arbre->propo[i]) {
                        i++;
                    }
                    if (i == max1) {
                        solution = corespondace(arbre->fg, bf);
                        return solution;
                    } else {
                        if (i == max2) {
                            solution = corespondace(arbre->fd, bf);
                            return solution;
                        } else {
                            if (bf->valeur[i] < arbre->propo[i]) {
                                solution = corespondace(arbre->fg, bf);
                                return solution;
                            } else {
                                if (bf->valeur[i] > arbre->propo[i]) {
                                    solution = corespondace(arbre->fd, bf);
                                    return solution;
                                }
                                return solution;


                            }
                        }
                    }
                }

            }
        }
    }
}
void comparaison_bc_bf_parielle(BC bc, BF bf){  // il ne faut pas tous les symptome de la bc mais juste que tous ceux de la bf soit dedans
    if(bc==NULL){                                  // affiche toutes les maladie propbable

    }else{
    if( comparaison(bc->arbre,bf)==1){
        printf("la conclusion peut etre %s\n",bc->conclusion->valeur);
        comparaison_bc_bf_parielle(bc->suivant,bf);

    }else{
        comparaison_bc_bf_parielle(bc->suivant,bf);
    }
    }

}

void comparaison_bc_bf_strict(BC bc, BF bf){
    if(bc==NULL){

    }else{
        if( comparaison_absolue(bc,bf)==1){
            printf("la conclusion peut etre %s\n",bc->conclusion->valeur);
            comparaison_bc_bf_parielle(bc->suivant,bf);

        }else{
            comparaison_bc_bf_parielle(bc->suivant,bf);
        }
    }
}

int comparaison(arbreb arbre,BF bf){

    int error=1;
    if(bf!=NULL && arbre!=NULL) {

        do {
            if(corespondace(arbre, bf)==0){
                error=0;
            }

            bf = bf->suivant;

        } while ((bf != NULL) && (error!=0) );
        if(error!=0 ){
            return 1;
        }
    }else{

        return 0;
    }
return 0;

}

int comparaison_absolue(BC bc,BF bf){

    int error=1;
    if(bf!=NULL ) {

        do {
            if(corespondace(bc->arbre, bf)==0){
                error=0;
            }

            bf = bf->suivant;

        } while ((bf != NULL) && (error!=0) );
        if(error!=0 && bc->nbpropo==nb_propo_bf(bf,0)){
            return 1;
        }
    }else{

        return 0;
    }
    return 0;

}
int nb_propo_bf(BF bf, int compt){

    if(bf!=NULL){

        compt=nb_propo_bf(bf->suivant,compt+1);
    }else{
        return compt;
    }
}


void menu_comparaison(BC bc,BF bf){
    int choix=0;
    while(choix!=1 && choix!=2) {
        printf("voulez vous une comparaison \n1)strict \n2)large ?\n");
        printf("une comparaison strict signifie qu'une regle et la base de fait doivent etre complemetement égale\nlarge signifie que il suffit que tous les élément de la base de fait soit dans uen regle");
        scanf("%d",&choix);
    }
    if(choix==1){
        comparaison_bc_bf_strict(bc,bf);
    }else{
        comparaison_bc_bf_parielle(bc,bf);
    }
}