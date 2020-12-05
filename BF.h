//
// Created by denis on 03/12/2020.
//

#ifndef PROJETLO21_BF_H
#define PROJETLO21_BF_H
#include "regle.h"
#include "bc.h"

typedef Proposition* BF;
void conitnuer();

BF creationBf();
BF menuBf(BC bc, BF bf);
void consulterBf(BF bf);
BF ajoutBf(BF bf);
BF suppBf(BF bf);
int confirmation();
BF suppressionfait(BF bf,char fait[]);
BF creerBf();
BF suppFait(BF bf);

#endif //PROJETLO21_BF_H
