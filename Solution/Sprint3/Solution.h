/**
 * @file Solution.h
 * @brief Prototypage des fonctions associées aux taquins solution
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#ifndef _SOLUTION_
#define _SOLUTION_

#include "Tableau2D.h"
#include "Etat.h"

void initialiser_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

void detruire_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

void afficher_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC);

bool but(Tab2D* solution, Tab2D &taquin);

#endif