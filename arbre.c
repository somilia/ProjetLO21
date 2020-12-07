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

int corespondace(arbreb arbre,BF bf){
    int solution=0;
if(arbre==NULL) {
    return 0;
}

else{
    if(bf->valeur[0]<arbre->propo[0]){
        solution=corespondace(arbre->fg,bf);
        return solution;
    }else{
        if(bf->valeur[0]>arbre->propo[0]){
            solution=corespondace(arbre->fd,bf);
            return solution;
        }else{
            if(strcmp(bf->valeur,arbre->propo)==0){
                return 1;
            }else{
                int i=1;//on commence i à un car on a deja tester le premiere element
                int max1 = strlen(bf->valeur);          // on utilise la fonction strlen ici pour la premire fois car comme c'est une fonction qui va réalisé un certain nombre d'action on attend avant dde l'utiliser pour la premiere fois la reponse du premier teste pour savoir si c'est nécéssaire
                int max2 = strlen(arbre->propo);
            while(i<max1 || i<max2 || bf->valeur[i]!=arbre->propo[i]){
                i++;
            }
            if(i==max1 ){
                solution=corespondace(arbre->fg,bf);
                return solution;
            }else{
                if(i==max2){
                    solution=corespondace(arbre->fd,bf);
                    return solution;
                }else{
                    if(bf->valeur[i]<arbre->propo[i]){
                        solution=corespondace(arbre->fg,bf);
                        return solution;
                }else{
                        if(bf->valeur[i]>arbre->propo[i]){
                            solution=corespondace(arbre->fd,bf);
                            return solution;
                    }

                }
            }
        }
        }
    }

}}}

/*void comparaison(arbreb arbre,BF bf){
    int compt=0;
    int error=1;
    if(bf!=NULL && arbre!=NULL) {
        do {
            compt = corespondace(arbre, bf);
            bf = bf->suivant;

        } while (bf != NULL || compt==0);
    }else{
        printf("erreur");
        error=0;
    }
    if(compt!=0 && error!=0){
        printf("%s",arbre->);
    }

}*/