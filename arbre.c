//
// Created by denis on 06/12/2020.
//

#include "arbre.h"
arbreb enraciner(arbreb a1,arbreb a2,int e){
    arbreb temp;
    temp=(noeud*)malloc(sizeof(noeud));
    temp->propo=NULL;
    temp->fd=a1;
    temp->fg=a2;
    return temp;
}

noeud *creerFeuille(Proposition *p){
    noeud *new=malloc(sizeof(noeud));
    new->fd=NULL;
    new->fg=NULL;
    new->propo=p;
    return new;
}
arbreb creerarbre(){
    noeud *new=malloc(sizeof(noeud));
    new->fd=NULL;
    new->fg=NULL;
    new->propo=NULL;
    arbreb newarbre=new;
    return newarbre;
}

arbreb creerarbre_complet(arbreb arbre, Proposition *r){

    if(arbre==NULL){
        return creerFeuille(r);

    }else{
        if(r->valeur<arbre->propo->valeur){
            arbre->fg=creerarbre_complet(arbre->fg,r);
            return arbre;
        }else{
            arbre->fd=creerarbre_complet(arbre->fd,r);
            return arbre;
        }
    }

}


arbreb inserer_regle_arbre(arbreb arbre, Proposition *r){

    while(r!=NULL){
        arbre=creerarbre_complet(arbre,r);
    }
    return arbre;
}

int ArbreEgale