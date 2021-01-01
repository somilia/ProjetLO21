#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "arbre.h"
#include "new_comparing.h"

arbreb enraciner(arbreb a1, arbreb a2, int e){

    arbreb temp;
    temp = (noeud*)malloc(sizeof(noeud));
    temp->propo[0] = ' ';
    temp->fd = a1;
    temp->fg = a2;
    return temp;
}

void supprimer_arbre(arbreb arbre){

    if(arbre==NULL){

    }else{
        supprimer_arbre(arbre->fg);
        supprimer_arbre(arbre->fd);
        free(arbre);
    }
}

noeud *creer_feuille(char *propo){

    noeud *new = malloc(sizeof(noeud));
    new->fd = NULL;
    new->fg = NULL;
    strcpy(new->propo,propo);
    return new;
}

arbreb creer_arbre(){

    noeud *new = malloc(sizeof(noeud));
    new->fd = NULL;
    new->fg = NULL;
    new->propo[0] = ' ';
    arbreb newarbre = new;
    return newarbre;
}

void afficher(arbreb arbre){

    if(arbre==NULL){

    }else{
        printf("%s\n",arbre->propo);
        afficher(arbre->fg);
        afficher(arbre->fd);
    }
}

arbreb creer_arbre_complet(arbreb arbre, char *propo){

    if(arbre==NULL){
        return creer_feuille(propo);

    }else{
        if(arbre->propo[0]==' '){
            return creer_feuille(propo);

        }else{
            if(propo[0]<arbre->propo[0]){
                arbre->fg = creer_arbre_complet(arbre->fg, propo);
                return arbre;

            }else{
                if(propo[0]>arbre->propo[0]){
                    arbre->fd = creer_arbre_complet(arbre->fd, propo);
                    return arbre;

                }else {
                    int i = 1;                 // on commence i à un car on a déjà testé le premier élément
                    int max1 = strlen(propo);  // on utilise la fonction strlen ici pour la première fois car comme c'est une fonction qui va réaliser un certain nombre d'action on attend avant de l'utiliser pour la première fois la reponse du premier teste pour savoir si c'est nécessaire
                    int max2 = strlen(arbre->propo);
                    while (i < max1 || i < max2 || propo[i] != arbre->propo[i]){
                        i++;
                    }
                    if (i==max1){
                        arbre->fg = creer_arbre_complet(arbre->fg, propo);
                        return arbre;

                    }else{
                        if (i==max2){
                            arbre->fd = creer_arbre_complet(arbre->fd, propo);
                            return arbre;

                        }else{
                            if (propo[i] < arbre->propo[i]){
                                arbre->fg = creer_arbre_complet(arbre->fg, propo);
                                return arbre;

                            }else{
                                if (propo[i] > arbre->propo[i]){
                                    arbre->fd = creer_arbre_complet(arbre->fd, propo);
                                    return arbre;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

Regle* inserer_regle_arbre(BC bc, BF bf){

    if(bc==NULL){
        return NULL;
    }

    if (correspondance(bc->arbre, bf)==1){
        return bc;
    }else{
        bc = bc->suivant;
        inserer_regle_arbre(bc, bf);
    }
}

bool correspondance(arbreb arbre, BF bf){

    int solution;
    if (arbre==NULL){
        return 0;

    }else{
        if (strcmp(bf->valeur, arbre->propo)==0){
            return 1;

        }else{
            if (bf->valeur[0] > arbre->propo[0]){
                solution = correspondance(arbre->fd, bf);
                return solution;

            }else{
                if (bf->valeur[0] < arbre->propo[0]){
                    solution = correspondance(arbre->fg, bf);
                    return solution;

                }else{
                    int i = 1;                      // on commence i à un car on a déjà testé le premier element
                    int max1 = strlen(bf->valeur);  // on utilise la fonction strlen ici pour la première fois car comme c'est une fonction qui va réaliser un certain nombre d'action on attend avant de l'utiliser pour la premiere fois la reponse du premier teste pour savoir si c'est nécéssaire
                    int max2 = strlen(arbre->propo);
                    while (i < max1 || i < max2 || bf->valeur[i] != arbre->propo[i]){
                        i++;
                    }
                    if (i==max1){
                        solution = correspondance(arbre->fg, bf);
                        return solution;

                    }else{
                        if (i==max2){
                            solution = correspondance(arbre->fd, bf);
                            return solution;

                        }else{
                            if (bf->valeur[i] < arbre->propo[i]){
                                solution = correspondance(arbre->fg, bf);
                                return solution;

                            }else{
                                if (bf->valeur[i] > arbre->propo[i]){
                                    solution = correspondance(arbre->fd, bf);
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

void comparaison_bc_bf_partielle(BC bc, BF bf){ // il ne faut pas tous les symptômes de la bc mais juste que tous ceux de la bf soient dedans
                                                // affiche toutes les maladies probables
    if(bc==NULL){

    }else{
        if(comparaison(bc->arbre, bf)==1){
            printf("la conclusion peut etre %s\n", bc->conclusion->valeur);
            comparaison_bc_bf_partielle(bc->suivant, bf);
        }else{
            comparaison_bc_bf_partielle(bc->suivant, bf);
        }
    }
}

void comparaison_bc_bf_strict(BC bc, BF bf){

    if(bc==NULL){

    }else{
        if(comparaison_absolue(bc, bf)==1){
            printf("la conclusion peut etre %s\n", bc->conclusion->valeur);
            comparaison_bc_bf_strict(bc->suivant, bf);

        }else{
            comparaison_bc_bf_strict(bc->suivant, bf);
        }
    }
}

bool comparaison(arbreb arbre, BF bf){

    int error = 1;
    if(bf!=NULL && arbre!=NULL){

        do {
            if(correspondance(arbre, bf)==0){
                error = 0;
            }
            bf = bf->suivant;
        } while ((bf!=NULL) && (error!=0));

        if(error!=0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

bool comparaison_absolue(BC bc, BF bf){

    int compt = 0;
    int error = 1;
    if(bf!=NULL){

        do {
            if(correspondance(bc->arbre, bf)==0){
                error = 0;
            }
            bf = bf->suivant;
            compt++;
        } while ((bf!=NULL) && (error!=0));

        if(error!=0 && bc->nbpropo==compt){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int nb_propo_bf(BF bf, int compt){

    if(bf!= NULL){

        compt = nb_propo_bf(bf->suivant,compt+1);
        printf("%d        ",compt);
        return compt;
    }else{
        printf("%d        ",compt);
        return compt;
    }
}

void menu_comparaison(BC bc,BF bf){

    int choix = 0;
    while(choix!=1 && choix!=2){
        printf("Voulez vous une comparaison \n1)Strict ? \n2)Large ?\n");
        printf("Ici, vous pouvez simplement comparer votre base de fait et il sera affiche toutes les regles contenant :\n ");
        printf("- Strict : exactement tous les element de la base de fait\n");
        printf("- Large : contenant toute la base de fait mais peu aussi contenir d'autres propositions\n");

        scanf("%d", &choix);
    }
    if(choix==1){
        comparaison_bc_bf_strict(bc, bf);
    }else{
        comparaison_bc_bf_partielle(bc, bf);
    }
    getch();
}