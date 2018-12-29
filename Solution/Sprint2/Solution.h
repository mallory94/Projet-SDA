#ifndef _SOLUTION_
#define _SOLUTION_

#include "Tableau2D.h"
#include "Etat.h"

void initialiser_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

void detruire_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

void afficher_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

bool etre_solution(Tab2D* solution, Tab2D &taquin);

#endif