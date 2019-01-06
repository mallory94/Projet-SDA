/**
 * @file Taquin.h
 * @brief Structuration du type Taquin et prototypage des fonctions associées
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

// Créer le jeu de taquin avec l'état initial
void initialiser(Taquin& t);

// Itération de l'algorithme de recherche
void jouer(Taquin& t);

// Afficher le contenu des listes à dev et dev
void afficher(Taquin& t);

/* vérifie si il éxiste un unique état de LEAE est de valeur
* g minimale
*
*/

// désalloue la mémoire du taquin
void detruire_taquin(Taquin& t);

#endif