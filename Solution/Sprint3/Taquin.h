/**
 * @file Taquin.h
 * @brief Structuration du type Taquin et prototypage des fonctions associ�es
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#ifndef _TAQUIN_
#define _TAQUIN_

#include "Etat.h"
#include "Liste.h"

struct Taquin {
	Liste LEAE;
	Liste LEE;
	unsigned int nbL;
	unsigned int nbC;
};

// Cr�er le jeu de taquin avec l'�tat initial
void initialiser(Taquin& t);

// It�ration de l'algorithme de recherche
bool jouer(Taquin& t);

// Afficher le contenu des listes � dev et dev
void afficher(Taquin& t);

/* v�rifie si il �xiste un unique �tat de LEAE est de valeur
* g minimale
*
*/

//renvoie vrai si l'�tat existe deja dans le taquin 
bool appartient(const Etat& ef, Taquin& t);

void ajouter_etat(Taquin &t, Liste &liste, Etat &e, Position_du_trou &position,
	unsigned int mouvement);

#endif