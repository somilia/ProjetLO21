#ifndef PROJETLO21_NEW_BC_H
#define PROJETLO21_NEW_BC_H

#include "allstructure.h"


/*********
 *
 * @param une base de connaissance BC
 * @return une base de connaissance BC
 * permet d'appliquer une base toute faite sur le thème du football
 */
BC BC_footchampiondumonde(BC bc);




/************
 *
 * @param une base de connaissance BC
 * @return une base de connaissance BC
 * permet d'arriver dans un menu contenant la liste des bases toutes faites
 */
BC bc_template(BC bc);


/*********
 *
 * @param une base de connaissance BC
 * @return une base de connaissance BC
 * permet d'appliquer une base toute faite sur le thème des maladies
 */
BC BC_maladie(BC bc);


#endif //PROJETLO21_NEW_BC_H