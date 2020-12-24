#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "allstructure.h"
#include "bf.h"
#include "regle.h"
#include "arbre.h"
#include "new_comparing.h"

int correspondance2(arbreb arbre, BF bf){

    int solution;
    if (arbre == NULL){
        return 0;
    }else{
        if (strcmp(bf->valeur, arbre->propo) == 0){
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
                    int i = 1; // on commence i à un car on a déjà tester le premier element
                    int max1 = strlen(bf->valeur); // on utilise la fonction strlen ici pour la première fois car comme c'est une fonction qui va réaliser un certain nombre d'action on attend avant de l'utiliser pour la première fois la reponse du premier teste pour savoir si c'est nécessaire
                    int max2 = strlen(arbre->propo);
                    while (i < max1 || i < max2 || bf->valeur[i] != arbre->propo[i]){
                        i++;
                    }
                    if (i == max1){
                        solution = correspondance(arbre->fg, bf);
                        return solution;

                    }else{
                        if (i == max2){
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

int comparaison2(Regle *regle, BF bf){

    int fin = 0;
    if(bf!=NULL && regle->arbre!=NULL){

        do {
            if (regle->reponse == 1){  // si la regle a deja été vérifié
                fin = 1;               // pas besoin de la reverifié
            }else{
                if(correspondance2(regle->arbre, bf) == 1){   //sinon si il y a corepondnance entre les la regle et la proposition actuelle de la base de fait
                    regle->nbpropovrai++;                     // on ajoute +1 aux nombre de proposition de la BC vrai
                }
            }
            bf = bf->suivant;          // on passe au fait suivant

        }while ((bf!=NULL) && fin==0);

        if(regle->nbpropo==regle->nbpropovrai && regle->reponse!=1){   // si il y a toutes les proposition qui sont vrai et que la regle n'avais pas deja été vérifie
            regle->reponse=1;          // alors la regle passe a deja ok
            return 1;                  // on retourne 1 pour dire qu'il y a une regle vai
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

BC reinitialisation_bc(BC bc){

    if(bc!=NULL){             // tant que la base n'est pas NULL
        bc->nbpropovrai = 0;  // on repasse le nb de proposition vrai a 0
        bc->suivant = reinitialisation_bc(bc->suivant);    // puis on passe a la règle suivante
        return bc;
    }
    else{
        return NULL;
    }
}

bool comparaison_bc_bf_partielle2(BC bc, BF bf){  // renvoi 1 si nouveau fait détecté vrai sinon 0

    if(bc==NULL){           // SI BC EST NULL et que aucun nouveau fait est vrai alors on renvoi 0
        return 0;
    }
    if (comparaison2(bc, bf) == 1){    // si il y a un nouveau fait détecté comme vrai
        bf = ajouteEnQueueRec(bf, bc->conclusion->valeur);     // on ajoute la conclusion de la règle vrai à la base de fait
        bc->reponse = 1;     // puis on passe réponse à 1 car on a plus besoin de vérifier cette règle

        return 1;            // on retourne 1 car il y a eu une modification

    }else{
        return comparaison_bc_bf_partielle2(bc->suivant, bf);  // si il y a pas eu la règle de vrai alors on passe a la règle suivante
    }
}

BC reinitialisation_complete_bc(BC bc){

    if(bc!=NULL){
        bc->nbpropovrai = 0;
        bc->reponse = 0;
        bc->suivant = reinitialisation_bc(bc->suivant);
        return bc;
    }
    else{
        return NULL;
    }
}

void menu_comparaison_automatique(BC bc, BF bf){

    while(comparaison_bc_bf_partielle2(bc, bf) == 1){   // tant que il y a eut une modification dans la boucle
        bc = reinitialisation_bc(bc);                   // on reinitialise les variables qui viennent d'être modifié avant de recommencer
    }
    bc = reinitialisation_complete_bc(bc);
    consulter_Bf(bf);
}