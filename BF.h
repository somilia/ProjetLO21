//
// Created by denis on 03/12/2020.
//

#ifndef PROJETLO21_BF_H
#define PROJETLO21_BF_H
#include "regle.h"

typedef Proposition* BF;

BF creationBf();
BF menuBf(BF bf);
void consulterBf(BF bf);
BF ajoutBf(BF bf);
BF suppBf(BF bf);

#endif //PROJETLO21_BF_H
